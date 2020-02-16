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
    triangulation.refine_global();

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
    cout << "max dofs per cell: " << DoFTools::max_dofs_per_cell(dof_handler) << endl;
    cout << "max connections: " << dof_handler.max_couplings_between_dofs() << endl;
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

enum renumberings {
    none,
    cuthill_McKee, 
    block_wise,
    clockwise_dg,
    hierarchical,
    random_renumbering,
    subdomain_wise
};

template <int dim = 2>
void distribute_dofs(
    Triangulation<dim> & triangulation, 
    renumberings renumbering_type = none, 
    int fe_degree = 1, 
    string file_name = "sparsity_pattern.svg")
{
    const FE_Q<2> finite_element(fe_degree);
    DoFHandler<2> dof_handler(triangulation);
    dof_handler.distribute_dofs(finite_element);
    cout << dof_handler;

    switch(renumbering_type)
    {
        case none:
            break;
        case cuthill_McKee:
            DoFRenumbering::Cuthill_McKee(dof_handler);
            break;
        case block_wise:
            DoFRenumbering::block_wise(dof_handler);
            break;
        case clockwise_dg:
            DoFRenumbering::clockwise_dg(dof_handler, Point<2>(0, 0));
            break;
        case hierarchical:
            DoFRenumbering::hierarchical(dof_handler);
            break;
        case random_renumbering:
            DoFRenumbering::random(dof_handler);
            break;
        case subdomain_wise:
            DoFRenumbering::subdomain_wise(dof_handler);
            break;
    }

    auto sparsity_pattern = generate_sparsity_pattern(dof_handler);
    dof_handler.clear();
        
    ofstream out(file_name);
    sparsity_pattern.print_svg(out);
    out.close();
}

int main(int argc, char** argv)
{

    renumberings renumbering_type = none;
    if(argc > 1)
    {
        renumbering_type = (renumberings)(argv[1][0] - '0');
    }
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
    distribute_dofs(tria_shell, renumbering_type, 1, "sparsity_pattern_1.svg");
    distribute_dofs(tria_shell, renumbering_type, 2, "sparsity_pattern_2.svg");
    distribute_dofs(tria_shell, renumbering_type, 3, "sparsity_pattern_3.svg");
    //TODO: experiment with other renumbering types
    return 0;
}