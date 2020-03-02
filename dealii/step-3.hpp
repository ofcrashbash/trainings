#pragma once

#include "step-1.hpp"
#include "step-2.hpp"
#include "step-3.hpp"

#include <deal.II/fe/fe_values.h>

#include <deal.II/base/quadrature_lib.h>

#include <deal.II/base/logstream.h>

#include <deal.II/numerics/matrix_tools.h>
#include <deal.II/numerics/vector_tools.h>
#include <deal.II/numerics/data_out.h>

#include <deal.II/base/function.h>
#include <deal.II/base/function_bessel.h>
#include <deal.II/base/function_lib.h>

#include <deal.II/lac/vector.h>
#include <deal.II/lac/full_matrix.h>
#include <deal.II/lac/solver_cg.h>
#include <deal.II/lac/precondition.h>

#include <vector>
#include <map>

//TODO make some inheritance between LaplaceEquationSolver and TrivialFunctionSolver classes

template <int dim>
class RightHandSide: public Function<dim>
{
    public:
        RightHandSide(): Function<dim>(){}

        virtual double value(const Point<dim> & p, const unsigned component = 0) const override
        {
            double return_value = 0;
            for(unsigned i = 0; i < dim; ++i)
                return_value += 4*pow(p(i), 4);

            return return_value;
        }
};

template <int dim>
double coeff(const Point< dim > & p)
{
    if (p.distance(Point< dim >()) < 0.5)
        return 10.;
    else 
        return 0.1;
}

template <int dim>
class BoundaryValues: public Function<dim>
{
    public:
        BoundaryValues(): Function<dim>(){}

        virtual double value(const Point<dim> & p, const unsigned /*component*/) const override
        {
            return 0;
        }
};

template <int dim = 2, int spacedim = dim>
class LaplaceEquationSolver
{
    public:

        LaplaceEquationSolver():
            fe(1), 
            dof_handler(triangulation)
        {
            deallog.depth_console(2);
        };

        void run(string grid_type_name, renumberings renumbering_type, string file_name = "solution")
        {
            make_grid(grid_type_name);
            setup_system(renumbering_type, file_name);
            assemble_system();
            solve();
            output_results(file_name);
        }

        double value(Point<dim> p = Point<dim>())
        {
            return VectorTools::point_value (dof_handler, solution, p);
        }

        double mean()
        {
            return VectorTools::compute_mean_value (dof_handler, QGauss<dim>(fe.degree + 1), solution, 0);
        }
    
    private:

        void make_grid(string grid_type_name)
        {
            grid_generator(triangulation, grid_type_name);
            triangulation.refine_global(2);
            cout << "Number of active cells: " << triangulation.n_active_cells() << endl;
            cout << "Total number of cells: " << triangulation.n_cells() << endl;
        }

        void setup_system(renumberings renumbering_type = none, string file_name = "solution")
        {
            //degree of freeedom
            dof_handler.distribute_dofs(fe);
            cout << "Number of degree of freedom: " << dof_handler.n_dofs() << endl;

            renumber<dim, spacedim>(dof_handler, renumbering_type);

            DynamicSparsityPattern dynamic_sparsity_pattern(dof_handler.n_dofs(), dof_handler.n_dofs());
            DoFTools::make_sparsity_pattern(dof_handler, dynamic_sparsity_pattern);
            sparsity_pattern.copy_from(dynamic_sparsity_pattern);   

            //save sparsity pattern to file
            ofstream out("sparsity_pattern_" + file_name + ".svg");
            sparsity_pattern.print_svg(out);
            out.close();

            system_matrix.reinit(sparsity_pattern);
            
            solution.reinit(dof_handler.n_dofs());
            system_rhs.reinit(dof_handler.n_dofs());
        }

        void assemble_system()
        {   
            RightHandSide< dim > right_hand_side;

            QGauss< dim > quadrature_formula(fe.degree + 1);
            FEValues< dim, spacedim > fe_values(fe, quadrature_formula, 
                update_values | update_gradients | update_JxW_values | update_quadrature_points);

            const unsigned dofs_per_cell = fe.dofs_per_cell;
            const unsigned n_q_points = quadrature_formula.size();

            vector<types::global_dof_index> local_dof_indices(dofs_per_cell);

            FullMatrix<double> cell_matrix(dofs_per_cell, dofs_per_cell);
            Vector<double> cell_rhs(dofs_per_cell);

            for(const auto& cell: dof_handler.active_cell_iterators())
            {
                fe_values.reinit(cell);

                cell_matrix = 0;
                cell_rhs = 0;

                for(unsigned q_index = 0; q_index < n_q_points; ++q_index)
                {
                    const auto x_q = fe_values.quadrature_point(q_index);

                    for(unsigned i = 0; i < dofs_per_cell; ++i)
                    {
                        for(unsigned j = 0; j < dofs_per_cell; ++j)
                        {
                            cell_matrix(i, j) += 
                                coeff(x_q) *
                                fe_values.shape_grad(i, q_index) *
                                fe_values.shape_grad(j, q_index) *
                                fe_values.JxW(q_index);
                        }

                        cell_rhs(i) += fe_values.shape_value(i, q_index) *
                            right_hand_side.value(x_q) *
                            fe_values.JxW(q_index);
                    }
                }

                cell->get_dof_indices(local_dof_indices);

                for(unsigned i = 0; i < dofs_per_cell; ++i)
                {
                    for(unsigned j = 0; j < dofs_per_cell; ++j)
                        system_matrix.add(
                            local_dof_indices[i],
                            local_dof_indices[j],
                            cell_matrix(i, j));

                    system_rhs(local_dof_indices[i]) += cell_rhs(i);
                }
            }

            map< types::global_dof_index, double > boundary_values;

            VectorTools::interpolate_boundary_values(
                dof_handler, 
                0, 
                BoundaryValues< dim >(),
                boundary_values);

            VectorTools::interpolate_boundary_values (dof_handler,
                1,
                Functions::CosineFunction< dim >(),
                boundary_values);

            MatrixTools::apply_boundary_values(
                boundary_values, 
                system_matrix,
                solution,
                system_rhs);
        }

        void solve()
        {
            SolverControl solver_control(1000, 1e-15);
            SolverCG< Vector < double > > solver(solver_control);

            PreconditionSSOR<> preconditioner;
            preconditioner.initialize(system_matrix, 1.2);

            solver.solve(system_matrix, solution, system_rhs, preconditioner);

            cout << "   " << solver_control.last_step()
                << " CG iterations needed to obtain convergence." << endl;
        }

        void output_results(string file_name = "solution") const
        {
            DataOut< dim > data_out;

            data_out.attach_dof_handler(dof_handler);
            data_out.add_data_vector(solution, file_name);
            data_out.build_patches();

            ofstream output(file_name + ".vtk");
            data_out.write_vtk(output);
        }

        Triangulation<dim, spacedim> triangulation;
        FE_Q< dim, spacedim > fe;
        DoFHandler< dim, spacedim > dof_handler;
        
        SparsityPattern sparsity_pattern;
        SparseMatrix< double > system_matrix;
        Vector< double > solution;
        Vector< double > system_rhs;
};


template <int dim = 2, int spacedim = dim>
class TrivialFunctionSolver
{
    public:

        TrivialFunctionSolver():
            fe(1), 
            dof_handler(triangulation)
        {
            deallog.depth_console(2);
        };

        void run(string grid_type_name = "hyper_cube", renumberings renumbering_type = none, int function_num = 0,  string file_name = "solution")
        {
            make_grid(grid_type_name);
            setup_system(renumbering_type, file_name);

            dealii::Function< dim > * func = NULL;
            switch(function_num)
            {
                case 0:
                    func = new Functions::ZeroFunction< dim >();
                    break;
                case 1:
                    func = new Functions::ConstantFunction< dim >(10);
                    break;
                case 2:
                    func = new Functions::Bessel1< dim >(1, 1);
                    break;
                case 3:
                    func = new Functions::SquareFunction< dim >();
                    break;
                case 4:
                    func = new Functions::CosineFunction< dim >();
                    break;
                case 5:
                    func = new Functions::ExpFunction< dim >();
                    break;
                default: 
                    throw MyException("unknown function type: " + function_num);
            }

            assemble_system(func);
            solve();
            output_results(file_name);
        }
    
    private:

        void make_grid(string grid_type_name)
        {
            grid_generator(triangulation, grid_type_name);
            triangulation.refine_global(5);
            cout << "Number of active cells: " << triangulation.n_active_cells() << endl;
        }

        void setup_system(renumberings renumbering_type = none, string file_name = "solution")
        {
            //degree of freeedom
            dof_handler.distribute_dofs(fe);
            cout << "Number of degree of freedom: " << dof_handler.n_dofs() << endl;

            renumber< dim, spacedim >(dof_handler, renumbering_type);

            DynamicSparsityPattern dynamic_sparsity_pattern(dof_handler.n_dofs(), dof_handler.n_dofs());
            DoFTools::make_sparsity_pattern(dof_handler, dynamic_sparsity_pattern);
            sparsity_pattern.copy_from(dynamic_sparsity_pattern);   

            //save sparsity pattern to file
            ofstream out("sparsity_pattern_" + file_name + ".svg");
            sparsity_pattern.print_svg(out);
            out.close();

            system_matrix.reinit(sparsity_pattern);
            
            solution.reinit(dof_handler.n_dofs());
            system_rhs.reinit(dof_handler.n_dofs());
        }

        void assemble_system(dealii::Function< dim > *function)
        {   
            QGauss< dim > quadrature_formula(fe.degree + 1);
            FEValues< dim, spacedim > fe_values(fe, quadrature_formula, 
                update_values | update_gradients | update_JxW_values | update_quadrature_points);

            const unsigned dofs_per_cell = fe.dofs_per_cell;
            const unsigned n_q_points = quadrature_formula.size();

            vector<types::global_dof_index> local_dof_indices(dofs_per_cell);

            FullMatrix< double > cell_matrix(dofs_per_cell, dofs_per_cell);
            Vector< double > cell_rhs(dofs_per_cell);

            for(const auto& cell: dof_handler.active_cell_iterators())
            {
                fe_values.reinit(cell);
                cell_matrix = 0;
                cell_rhs = 0;

                for(unsigned q_index = 0; q_index < n_q_points; ++q_index)
                {
                    for(unsigned i = 0; i < dofs_per_cell; ++i)
                    {
                        for(unsigned j = 0; j < dofs_per_cell; ++j)
                        {
                            cell_matrix(i, j) += 
                                fe_values.shape_value(i, q_index) *
                                fe_values.shape_value(j, q_index) *
                                fe_values.JxW(q_index);
                        }

                        cell_rhs(i) += fe_values.shape_value(i, q_index) *
                            function->value(fe_values.quadrature_point(i)) *
                            fe_values.JxW(q_index);
                    }
                }

                cell->get_dof_indices(local_dof_indices);

                for(unsigned i = 0; i < dofs_per_cell; ++i)
                {
                    for(unsigned j = 0; j < dofs_per_cell; ++j)
                        system_matrix.add(
                            local_dof_indices[i],
                            local_dof_indices[j],
                            cell_matrix(i, j));

                    system_rhs(local_dof_indices[i]) += cell_rhs(i);
                }
            }
        }

        void solve()
        {
            SolverControl solver_control(1000, 1e-30);
            SolverCG< Vector< double > > solver(solver_control);

            solver.solve(system_matrix, solution, system_rhs, PreconditionIdentity());
        }

        void output_results(string file_name = "solution") const
        {
            DataOut< dim > data_out;

            data_out.attach_dof_handler(dof_handler);
            data_out.add_data_vector(solution, file_name);
            data_out.build_patches();

            ofstream output(file_name + ".vtk");
            data_out.write_vtk(output);
        }

        Triangulation< dim, spacedim > triangulation;
        FE_Q< dim, spacedim > fe;
        DoFHandler< dim, spacedim > dof_handler;
        
        SparsityPattern sparsity_pattern;
        SparseMatrix< double > system_matrix;
        Vector< double > solution;
        Vector< double > system_rhs;
};

void step_3_main();