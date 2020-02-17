#include "step-1-2.hpp"
#include "step-3.hpp"

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
    
    //step-3
    LaplaceEquationSolver a;
    a.run();
    
    return 0;
}