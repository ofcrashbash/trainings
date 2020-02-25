#include "step-1.hpp"
#include "step-2.hpp"
#include "step-3.hpp"

#include <deal.II/dofs/dof_accessor.h>

#include <deal.II/fe/fe_values.h>
#include <deal.II/base/quadrature_lib.h>

#include <deal.II/numerics/vector_tools.h>
#include <deal.II/base/function.h>

#include <deal.II/lac/full_matrix.h>

#include <deal.II/lac/solver_cg.h>
#include <deal.II/lac/precondition.h>

#include <deal.II/numerics/data_out.h>

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
using namespace dealii;

LaplaceEquationSolver::LaplaceEquationSolver():
    fe(1),
    dof_handler(triangulation)
{
    deallog.depth_console(2);
}

void LaplaceEquationSolver::make_grid(unsigned mesh_id)
{
    switch(mesh_id)
    {
        case 0:
            GridGenerator::hyper_cube<2>(triangulation, -1, 1);
            break;
        case 1:
            GridGenerator::hyper_cube_slit(triangulation, 0, 1, false);
            break;
        case 2:
            GridGenerator::half_hyper_ball(triangulation, Point<2>(0, 0), 1.0);
            break;
        case 3: 
            GridGenerator::hyper_shell(triangulation, Point<2>(0, 0), 0.1, 1, 6, true);
            break;
        case 4:
            {
                vector<Point<2>> vertices{Point<2>(-1, 0), Point<2>(1, 0), Point<2>(0, 1)};
                GridGenerator::simplex(triangulation,  vertices);
            }
            break;
        case 5:
            GridGenerator::hyper_cube_with_cylindrical_hole(triangulation);
            break;
        default:
            throw "non mesh type specified";

    }
    triangulation.refine_global(2);

    cout << "Number of active cells: " << triangulation.n_active_cells() << endl;
}

void LaplaceEquationSolver::setup_system()
{
    //degree of freeedom
    dof_handler.distribute_dofs(fe);
    cout << "Number of degree of freedom: " << dof_handler.n_dofs() << endl;

    DynamicSparsityPattern dynamic_sparsity_pattern(dof_handler.n_dofs(), dof_handler.n_dofs());
    DoFTools::make_sparsity_pattern(dof_handler, dynamic_sparsity_pattern);
    sparsity_pattern.copy_from(dynamic_sparsity_pattern);   

    //save sparsity pattern to file
    ofstream out("sparsity_pattern.svg");
    sparsity_pattern.print_svg(out);
    out.close();

    system_matrix.reinit(sparsity_pattern);

    solution.reinit(dof_handler.n_dofs());
    system_rhs.reinit(dof_handler.n_dofs());
}

void LaplaceEquationSolver::assemble_system()
{   
    QGauss<2> quadrature_formula(fe.degree + 1);
    FEValues<2> fe_values(fe, quadrature_formula, update_values | update_gradients | update_JxW_values);

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

void LaplaceEquationSolver::solve()
{
    SolverControl solver_control(1000, 1e-30);
    SolverCG<Vector<double>> solver(solver_control);
    
    solver.solve(system_matrix, solution, system_rhs, PreconditionIdentity());
}

void LaplaceEquationSolver::output_results() const
{
    DataOut<2> data_out;

    data_out.attach_dof_handler(dof_handler);
    data_out.add_data_vector(solution, "solution");
    data_out.build_patches();

    ofstream output("solution.vtk");
    data_out.write_vtk(output);
}

void LaplaceEquationSolver::run(unsigned mesh_id)
{
    make_grid(mesh_id);
    setup_system();
    assemble_system();
    solve();
    output_results();
}