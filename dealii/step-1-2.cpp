#include "step-1-2.hpp"

void save(Triangulation<2> &triangulation, string name)
{
    std::ofstream out(name + ".svg");
    GridOut grid_out;
    grid_out.write_svg(triangulation, out);
    cout << "grid written to \"" + name + ".svg\"" << endl;
}

Triangulation<2> hyper_cube_grid(unsigned n_ref)
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


SparsityPattern generate_sparsity_pattern(DoFHandler<2> &dof_handler)
{    
    DynamicSparsityPattern dynamic_sparsity_pattern(dof_handler.n_dofs(), dof_handler.n_dofs());
    DoFTools::make_sparsity_pattern(dof_handler, dynamic_sparsity_pattern);

    SparsityPattern sparsity_pattern;
    sparsity_pattern.copy_from(dynamic_sparsity_pattern);

    return sparsity_pattern;
}