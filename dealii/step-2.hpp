#pragma once

#include "step-1.hpp"

#include <deal.II/dofs/dof_handler.h>
#include <deal.II/dofs/dof_tools.h>
#include <deal.II/dofs/dof_renumbering.h>

#include <deal.II/fe/fe_q.h>
#include <deal.II/fe/fe_dgq.h>

#include <deal.II/lac/sparse_matrix.h>
#include <deal.II/lac/dynamic_sparsity_pattern.h>

SparsityPattern generate_sparsity_pattern(DoFHandler<2> &dof_handler);

enum renumberings 
{
    none,
    cuthill_McKee, 
    hierarchical,
    random_renumbering,
    block_wise,
    clockwise_dg,
    subdomain_wise
};

template <int dim = 2, int spacedim = dim>
void renumber(DoFHandler<dim, spacedim> & dof_handler, renumberings renumbering_type)
{
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
            DoFRenumbering::clockwise_dg(dof_handler, Point<dim>(0, 0));
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
}

template <int dim = 2, int spacedim = dim>
void distribute_dofs(
    Triangulation<dim> & triangulation, 
    renumberings renumbering_type = none, 
    int fe_degree = 1, 
    string file_name = "sparsity_pattern.svg")
{
    const FE_Q<dim, spacedim> finite_element(fe_degree);
    DoFHandler<dim, spacedim> dof_handler(triangulation);
    dof_handler.distribute_dofs(finite_element);
    cout << dof_handler;

    renumber(dof_handler, renumbering_type);

    auto sparsity_pattern = generate_sparsity_pattern(dof_handler);
    dof_handler.clear();
        
    ofstream out(file_name);
    sparsity_pattern.print_svg(out);
    out.close();
}

template <int dim = 2>
ostream& operator<<(ostream &out, const DoFHandler<dim>& dof_handler)
{
    cout << "DoF Handler info" << endl;
    cout << "number of dofs: " << dof_handler.n_dofs() << endl;
    cout << "number of boundary dofs: " << dof_handler.n_boundary_dofs() << endl;
    cout << "max connections: " << dof_handler.max_couplings_between_dofs() << endl;
    return out;
}

void step_2_main();