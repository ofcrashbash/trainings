#pragma once

#include "step-1.hpp"
#include "step-2.hpp"
#include "step-3.hpp"

#include <deal.II/fe/fe_values.h>

#include <deal.II/base/quadrature_lib.h>

#include <deal.II/numerics/matrix_tools.h>
#include <deal.II/numerics/vector_tools.h>
#include <deal.II/numerics/data_out.h>
#include <deal.II/base/function.h>

#include <deal.II/lac/vector.h>
#include <deal.II/lac/full_matrix.h>
#include <deal.II/lac/solver_cg.h>
#include <deal.II/lac/precondition.h>

#include <vector>
#include <string>

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

    private:

        void make_grid(string grid_type_name)
        {
            grid_generator(triangulation, grid_type_name);
            triangulation.refine_global(2);
            cout << "Number of active cells: " << triangulation.n_active_cells() << endl;
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
            QGauss<dim> quadrature_formula(fe.degree + 1);
            FEValues<dim, spacedim> fe_values(fe, quadrature_formula, update_values | update_gradients | update_JxW_values);

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
                    for(unsigned i = 0; i < dofs_per_cell; ++i)
                    {
                        for(unsigned j = 0; j < dofs_per_cell; ++j)
                        {
                            cell_matrix(i, j) += 
                                fe_values.shape_grad(i, q_index) *
                                fe_values.shape_grad(j, q_index) *
                                fe_values.JxW(q_index);
                        }

                        cell_rhs(i) += fe_values.shape_value(i, q_index) *
                            1 *
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

            map<types::global_dof_index, double> boundary_values;

            VectorTools::interpolate_boundary_values(
                dof_handler, 
                0, 
                Functions::ZeroFunction<2>(),
                boundary_values);

            MatrixTools::apply_boundary_values(
                boundary_values, 
                system_matrix,
                solution,
                system_rhs);
        }

        void solve()
        {
            SolverControl solver_control(1000, 1e-30);
            SolverCG<Vector<double>> solver(solver_control);

            solver.solve(system_matrix, solution, system_rhs, PreconditionIdentity());
        }

        void output_results(string file_name = "solution") const
        {
            DataOut<dim> data_out;

            data_out.attach_dof_handler(dof_handler);
            data_out.add_data_vector(solution, file_name);
            data_out.build_patches();

            ofstream output(file_name + ".vtk");
            data_out.write_vtk(output);
        }

        Triangulation<dim, spacedim> triangulation;
        FE_Q<dim,spacedim> fe;
        DoFHandler<dim, spacedim> dof_handler;

        SparsityPattern sparsity_pattern;
        SparseMatrix<double> system_matrix;
        Vector<double> solution;
        Vector<double> system_rhs;
};