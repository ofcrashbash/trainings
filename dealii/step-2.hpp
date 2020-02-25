#pragma once

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

using namespace dealii;
using namespace std; 

SparsityPattern generate_sparsity_pattern(DoFHandler<2> &dof_handler);

enum renumberings 
{
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
    const FE_Q<dim> finite_element(fe_degree);
    DoFHandler<dim> dof_handler(triangulation);
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