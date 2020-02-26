#include "step-2.hpp"

SparsityPattern generate_sparsity_pattern(DoFHandler<2> &dof_handler)
{    
    DynamicSparsityPattern dynamic_sparsity_pattern(dof_handler.n_dofs(), dof_handler.n_dofs());
    DoFTools::make_sparsity_pattern(dof_handler, dynamic_sparsity_pattern);

    SparsityPattern sparsity_pattern;
    sparsity_pattern.copy_from(dynamic_sparsity_pattern);

    return sparsity_pattern;
}

void step_2_main()
{
    Triangulation<2> tria_shell;
    grid_generator(tria_shell, "hyper_shell");
    save(tria_shell, "hyper_shell_2d");
    cout << tria_shell;

    renumberings renumbering_type = none;

    //Sparsity patterns and distribution of dofs
    distribute_dofs(tria_shell, renumbering_type, 1, "sparsity_pattern_1.svg");
    distribute_dofs(tria_shell, renumbering_type, 2, "sparsity_pattern_2.svg");
    distribute_dofs(tria_shell, renumbering_type, 3, "sparsity_pattern_3.svg");
}