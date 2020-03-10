#pragma once

#include "step-1.hpp"
#include "step-2.hpp"
#include "step-3.hpp"

#include <deal.II/fe/fe_values.h>

#include <deal.II/base/quadrature_lib.h>
#include <deal.II/base/logstream.h>
#include <deal.II/base/smartpointer.h>
#include <deal.II/base/convergence_table.h>

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

#include <deal.II/lac/affine_constraints.h>
#include <deal.II/grid/grid_refinement.h>
#include <deal.II/numerics/error_estimator.h>

#include <vector>
#include <array>
#include <fstream>
#include <iostream>
#include <map>

//TODO make some inheritance between LaplaceEquationSolver and TrivialFunctionSolver classes
namespace step_3{

    template <int dim>
    class RightHandSide: public Function<dim>
    {
        public:
            RightHandSide(): Function<dim>(){}

            virtual double value(const Point<dim> & p, const unsigned component = 0) const override
            {
                return 1.;
            }
    };

    template <int dim>
    double coeff(const Point< dim > & p)
    {
        if (p.square() < 0.5 * 0.5)
            return 1.;
        else 
            return 1.;
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
                fe(2), 
                dof_handler(triangulation)
            {
                deallog.depth_console(2);
            };

            void run(renumberings renumbering_type, string file_name = "solution")
            {   

                //NOTE it crashes when cycle == 3.
                for(unsigned cycle = 0; cycle < 8; ++cycle)
                {
                    cout << "Cycle: " << cycle << endl;

                    if (cycle == 0)
                        make_grid();
                    else
                        refine_grid();

                    //if (grid_type_name.compare("hyper_ball") == 0 && triangulation.n_levels() >= 3 && dim == 3)
                    //    throw MyException("hyper_ball has some erro if refined three times");

                    setup_system(renumbering_type, file_name + "_refine_" + to_string(cycle));
                    assemble_system();
                    solve();
                    process_solution(cycle);
                }
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

            double process_solution(const unsigned cycle)
            {
                Vector< double > difference_per_cell(triangulation.n_active_cells());
                VectorTools::integrate_difference(
                    dof_handler, 
                    solution,
                    ZeroFunction< dim >(),
                    difference_per_cell,
                    QGauss< dim >(fe.degree + 1),
                    VectorTools::L2_norm);

                const double L2_error = VectorTools::compute_global_error(triangulation, difference_per_cell, VectorTools::L2_norm);

                VectorTools::integrate_difference(
                    dof_handler, 
                    solution,
                    ZeroFunction< dim >(),
                    difference_per_cell,
                    QGauss< dim >(fe.degree + 1),
                    VectorTools::H1_seminorm);

                const double H1_error = VectorTools::compute_global_error(triangulation, difference_per_cell, VectorTools::H1_seminorm);


                const QTrapez<1> q_trapez;
                const QIterated< dim > q_iterated(q_trapez, 2*fe.degree + 1);
                VectorTools::integrate_difference(
                    dof_handler,
                    solution, 
                    ZeroFunction< dim >(), 
                    difference_per_cell, 
                    q_iterated,
                    VectorTools::Linfty_norm);

                const double Linfty_norm = VectorTools::compute_global_error(triangulation, difference_per_cell, VectorTools::Linfty_norm);

                const unsigned n_active_cells = triangulation.n_active_cells();
                const unsigned n_dofs         = dof_handler.n_dofs();
                
                convergence_table.add_value("cycle", cycle);
                convergence_table.add_value("cells", n_active_cells);
                convergence_table.add_value("dofs", n_dofs);
                convergence_table.add_value("L2", L2_error);
                convergence_table.add_value("H1", H1_error);
                convergence_table.add_value("Linfty", Linfty_norm);

                return L2_error + Linfty_norm;
            }

        private:

            void make_grid()
            {
                GridGenerator::hyper_cube(triangulation);
                triangulation.begin_active()->face(0)->set_boundary_id(1);
                triangulation.begin_active()->face(1)->set_boundary_id(2);
                triangulation.begin_active()->face(2)->set_boundary_id(3);
                triangulation.begin_active()->face(3)->set_boundary_id(4);
                triangulation.refine_global(2);
                cout << "Number of active cells: " << triangulation.n_active_cells() << endl;
                cout << "Total number of cells: " << triangulation.n_cells() << endl;

                ofstream out("hyper_cube.msh");
                GridOutFlags::Msh msh;
                msh.write_faces = true;
                msh.write_lines = true;
                GridOut grid_out;
                grid_out.set_flags(msh);
                grid_out.write_msh(triangulation, out);
                out.close();
            }

            void setup_system(renumberings renumbering_type = none, string file_name = "solution")
            {
                //degree of freeedom
                dof_handler.distribute_dofs(fe);
                cout << "Number of degree of freedom: " << dof_handler.n_dofs() << endl;

                renumber<dim, spacedim>(dof_handler, renumbering_type);

                solution.reinit(dof_handler.n_dofs());
                system_rhs.reinit(dof_handler.n_dofs());

                constraints.clear();

                DoFTools::make_hanging_node_constraints(
                    dof_handler, 
                    constraints);

                VectorTools::interpolate_boundary_values(
                    dof_handler, 
                    1, Functions::ZeroFunction< dim >(),
                    constraints);
                
                VectorTools::interpolate_boundary_values(
                    dof_handler, 
                    2, Functions::ConstantFunction< dim >(1),
                    constraints);

                constraints.close();

                DynamicSparsityPattern dsp(dof_handler.n_dofs());
                DoFTools::make_sparsity_pattern(
                    dof_handler, 
                    dsp, 
                    constraints, 
                    false);

                sparsity_pattern.copy_from(dsp);
                
                system_matrix.reinit(sparsity_pattern);

                //save sparsity pattern
                ofstream out("sparsity_pattern_" + file_name + ".svg");
                sparsity_pattern.print_svg(out);
                out.close();

            }

            void refine_grid()
            {
                Vector< float > estimate_error_per_cell(triangulation.n_active_cells());

                KellyErrorEstimator< dim >::estimate(
                    dof_handler,
                    QGauss< dim - 1 >(fe.degree + 1), 
                    map< types::boundary_id, const Function< dim > *>(),
                    solution, 
                    estimate_error_per_cell
                );

                GridRefinement::refine_and_coarsen_fixed_number(
                    triangulation, 
                    estimate_error_per_cell,
                    0.3, 
                    0.03
                );

                triangulation.execute_coarsening_and_refinement();
            }

            void assemble_system()
            {   
                QGauss< dim > quadrature_formula(fe.degree + 1);
                QGauss< dim - 1> face_quadrature_formula(fe.degree + 1);

                FEValues< dim, spacedim > fe_values(fe, quadrature_formula, 
                    update_values | update_gradients | update_JxW_values | update_quadrature_points);

                FEFaceValues<dim> fe_face_values(fe,
                    face_quadrature_formula,
                    update_values | update_quadrature_points | update_normal_vectors | update_JxW_values);

                const unsigned dofs_per_cell = fe.dofs_per_cell;
                const unsigned n_q_points = quadrature_formula.size();
                const unsigned n_face_q_points = face_quadrature_formula.size();

                FullMatrix< double > cell_matrix(dofs_per_cell, dofs_per_cell);
                Vector< double > cell_rhs(dofs_per_cell);

                vector< types::global_dof_index > local_dof_indices(dofs_per_cell);

                RightHandSide< dim > right_hand_side;

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
                                cell_matrix(i, j) += 
                                    coeff< dim >(x_q) *
                                    fe_values.shape_grad(i, q_index) *
                                    fe_values.shape_grad(j, q_index) *
                                    fe_values.JxW(q_index);

                            cell_rhs(i) += fe_values.shape_value(i, q_index) *
                                right_hand_side.value(x_q) *
                                fe_values.JxW(q_index);
                        }
                    }

                    for(unsigned face_number = 0; face_number < GeometryInfo<dim>::faces_per_cell; ++face_number)
                    {
                        if(cell->face(face_number)->at_boundary() && (cell->face(face_number)->boundary_id() == 3 || cell->face(face_number)->boundary_id() == 4))
                        {
                            fe_face_values.reinit(cell, face_number);

                            for(unsigned q_point = 0; q_point < n_face_q_points; ++q_point)
                            {
                                const double neuman_value = -2;
                                for(unsigned i = 0; i < dofs_per_cell; ++i)
                                    cell_rhs(i) += 
                                        neuman_value * 
                                        fe_face_values.shape_value(i, q_point)*
                                        fe_face_values.JxW(q_point);

                            }
                        }
                    }

                    cell->get_dof_indices(local_dof_indices);
                    constraints.distribute_local_to_global(
                        cell_matrix, 
                        cell_rhs, 
                        local_dof_indices, 
                        system_matrix, 
                        system_rhs);
                }
            }

            void solve()
            {
                SolverControl solver_control(1000, 1e-12);
                SolverCG< Vector < double > > solver(solver_control);

                //TODO try different preconditions Jacobi, SparseILU
                PreconditionSSOR<> preconditioner;
                preconditioner.initialize(system_matrix, 1.2);

                solver.solve(
                    system_matrix, 
                    solution, 
                    system_rhs, 
                    preconditioner);

                constraints.distribute(solution);

                cout << "   " << solver_control.last_step()
                    << " CG iterations needed to obtain convergence." << endl;
            }

            void output_results(string file_name = "solution")
            {
                DataOut< dim > data_out;

                data_out.attach_dof_handler(dof_handler);
                data_out.add_data_vector(solution, file_name);
                data_out.build_patches();

                ofstream output(file_name + ".vtk");
                data_out.write_vtk(output);


                //convergence table
                convergence_table.set_precision("L2", 3);
                convergence_table.set_precision("H1", 3);
                convergence_table.set_precision("Linfty", 3);
                convergence_table.set_scientific("L2", true);
                convergence_table.set_scientific("H1", true);
                convergence_table.set_scientific("Linfty", true);
                convergence_table.set_tex_caption("cells", "\\# cells");
                convergence_table.set_tex_caption("dofs", "\\# dofs");
                convergence_table.set_tex_caption("L2", "@f$L^2@f$-error");
                convergence_table.set_tex_caption("H1", "@f$H^1@f$-error");
                convergence_table.set_tex_caption("Linfty", "@f$L^\\infty@f$-error");
                convergence_table.set_tex_format("cells", "r");
                convergence_table.set_tex_format("dofs", "r");
                std::cout << std::endl;
                convergence_table.write_text(std::cout);

                string error_filename = "error.tex";
                std::ofstream error_table_file(error_filename);
                convergence_table.write_tex(error_table_file);
            }

            Triangulation<dim, spacedim> triangulation;
            FE_Q< dim, spacedim > fe;
            DoFHandler< dim, spacedim > dof_handler;

            AffineConstraints< double > constraints;

            SparsityPattern sparsity_pattern;
            SparseMatrix< double > system_matrix;

            Vector< double > solution;
            Vector< double > system_rhs;

            ConvergenceTable convergence_table;
    };

    void run();
}