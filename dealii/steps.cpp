#include <deal.II/grid/tria.h>
#include <deal.II/grid/tria_accessor.h>
#include <deal.II/grid/tria_iterator.h>
#include <deal.II/grid/grid_generator.h>
#include <deal.II/grid/grid_out.h>
#include <deal.II/grid/manifold_lib.h>

#include <deal.II/dofs/dof_handler.h>
#include <deal.II/dofs/dof_tools.h>
#include <deal.II/dofs/dof_renumbering.h>

#include <deal.II/fe/fe_q.h>
#include <deal.II/fe/fe_dgq.h>

#include <deal.II/lac/sparse_matrix.h>
#include <deal.II/lac/dynamic_sparsity_pattern.h>

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
using namespace dealii;

void save(Triangulation<2> &triangulation, string name)
{
    std::ofstream out(name + ".svg");
    GridOut grid_out;
    grid_out.write_svg(triangulation, out);
    cout << "grid written to \"" + name + ".svg\"" << endl;
}

Triangulation<2> hyper_cube_grid(unsigned n_ref = 0)
{
    Triangulation<2> triangulation;
    GridGenerator::hyper_cube(triangulation);
    triangulation.refine_global(n_ref);
    return triangulation;
}

Triangulation<2> hyper_cube_slit()
{
    Triangulation<2> triangulation;
    GridGenerator::hyper_cube_slit(triangulation, 0, 1, false);
    triangulation.refine_global(4);
    return triangulation;
}

Triangulation<2> half_hyper_ball()
{
    Triangulation<2> triangulation;
    GridGenerator::half_hyper_ball(triangulation, Point<2>(0, 0), 1.0);
    triangulation.refine_global(4);
    return triangulation;
}

Triangulation<2> hyper_shell()
{
    Triangulation<2> triangulation;
    GridGenerator::hyper_shell(triangulation, Point<2>(0, 0), 0.1, 1, 6, true);
    triangulation.refine_global(3);

    for(auto& cell: triangulation.active_cell_iterators())
    {
        auto dist = (cell->center()).distance(Point<2>(0, 0));
        auto threshold = ((double) rand() / (RAND_MAX));
        if(dist > threshold)
        {
            cell->set_refine_flag();
        }
    }
    triangulation.execute_coarsening_and_refinement();
    return triangulation;
}

template <int dim = 2>
ostream& operator<<(ostream &out, const Triangulation<dim>& triangulation)
{   
    out << "Triangulation info" << endl;
    out << "dim: " << triangulation.dimension << endl;
    out << "n_active_cells: " << triangulation.n_active_cells() << endl;
    out << "n_active_faces: " << triangulation.n_active_faces() << endl;
    out << "n_active_lines: " << triangulation.n_active_lines() << endl;
    out << "n_active_quads: " << triangulation.n_active_quads() << endl;
    out << "n_global_active_cells: " << triangulation.n_global_active_cells() << endl;
    out << "n_global_levels: " << triangulation.n_global_levels() << endl;
    out << "n_levels: " << triangulation.n_levels() << endl;

    return out;
}

template <int dim = 2>
ostream& operator<<(ostream &out, const DoFHandler<dim>& dof_handler)
{
    cout << "DoF Handler info" << endl;
    cout << "number of dofs: " << dof_handler.n_dofs() << endl;
    cout << "number of boundary dofs: " << dof_handler.n_boundary_dofs() << endl;
    return out;
} 


SparsityPattern generate_sparsity_pattern(DoFHandler<2> &dof_handler)
{    
    DynamicSparsityPattern dynamic_sparsity_pattern(dof_handler.n_dofs(), dof_handler.n_dofs());
    DoFTools::make_sparsity_pattern(dof_handler, dynamic_sparsity_pattern);

    SparsityPattern sparsity_pattern;
    sparsity_pattern.copy_from(dynamic_sparsity_pattern);

    return sparsity_pattern;
}

int main(int argc, char** argv)
{
    //Mesh generation
    auto tria_cube_split = hyper_cube_slit();
    save(tria_cube_split, "hyper_cube_slit");
    cout << tria_cube_split;

    auto tria_half_ball = half_hyper_ball();
    save(tria_half_ball, "half_hyper_ball");
    cout << tria_half_ball;

    auto tria_shell = hyper_shell();
    save(tria_shell, "hyper_shell");
    cout << tria_shell;
    
    auto tria_cube = hyper_cube_grid(2);
    save(tria_cube, "hyper_cube_grid");
    cout << tria_cube;

    //Sparsity patterns and distribution of dofs
    const FE_Q<2> finite_element(1);
    DoFHandler<2> dof_handler(tria_shell);
    dof_handler.distribute_dofs(finite_element);
    ofstream out("sparsity_pattern.svg");
    {
        auto sparsity_pattern = generate_sparsity_pattern(dof_handler);

        cout << dof_handler;
        dof_handler.clear();
        
        sparsity_pattern.print_svg(out);
        out.close();
    }

    //reordered sparsity pattern
    dof_handler.initialize(tria_shell, finite_element);
    dof_handler.distribute_dofs(finite_element);
    DoFRenumbering::Cuthill_McKee(dof_handler);
    {
        auto sparsity_pattern = generate_sparsity_pattern(dof_handler);

        cout << dof_handler;
        dof_handler.clear();
        out.open("sparsity_pattern_renumbered.svg");
        sparsity_pattern.print_svg(out);
        out.close();
    }

    //double reordered sparsity pattern
    dof_handler.initialize(tria_shell, finite_element);
    dof_handler.distribute_dofs(finite_element);
    DoFRenumbering::Cuthill_McKee(dof_handler);
    DoFRenumbering::Cuthill_McKee(dof_handler);
    {
        auto sparsity_pattern = generate_sparsity_pattern(dof_handler);

        cout << dof_handler;
        dof_handler.clear();
        out.open("sparsity_pattern_double_renumbered.svg");
        sparsity_pattern.print_svg(out);
        out.close();
    }
    //TODO: experiment with other renumbering types
    return 0;
}