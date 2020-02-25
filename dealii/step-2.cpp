#include "step-2.hpp"

SparsityPattern generate_sparsity_pattern(DoFHandler<2> &dof_handler)
{    
    DynamicSparsityPattern dynamic_sparsity_pattern(dof_handler.n_dofs(), dof_handler.n_dofs());
    DoFTools::make_sparsity_pattern(dof_handler, dynamic_sparsity_pattern);

    SparsityPattern sparsity_pattern;
    sparsity_pattern.copy_from(dynamic_sparsity_pattern);

    return sparsity_pattern;
}