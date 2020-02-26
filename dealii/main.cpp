#include "step-1.hpp"
#include "step-2.hpp"
#include "step-3.hpp"

#include <map>

int main(int argc, char** argv)
{
    renumberings renumbering_type = none;
    string grid_type = "none";
    if(argc == 2)
    {
        renumbering_type = (renumberings)(argv[1][0] - '0');
    }
    else if(argc == 3)
        grid_type = argv[2];

    //step - 1
    auto grids_types_array = vector<string>
    {
        "hyper_cube_slit",
        "half_hyper_ball",
        "hyper_shell",
        "hyper_cube",
        "subdivided_hyper_cube",
        "simplex",
        "cheese",
        "plate_with_a_hole",
        "parallelogram",
        "parallelepiped",
        "enclosed_hyper_cube",
        "hyper_ball",
        "hyper_sphere",
        "quarter_hyper_ball",
        "cylinder",
        "truncated_cone",
        "hyper_cross",
        "hyper_L",
        "cylinder_shell",
        "hyper_cube_with_cylindrical_hole",
        "concentric_hyper_shells",
        "moebius"
    };

    Triangulation<1> tria_1d;
    for(auto grid_type_name: grids_types_array)
    {
        tria_1d.clear();
        try
        {
            grid_generator(tria_1d, grid_type_name);
            tria_1d.refine_global(3);
            save(tria_1d, grid_type_name + "_1d");
        } catch(const MyException& caught)
        {
            cout<<"Got :\" " << caught.what() << "\"" <<endl;
        }
    }

    Triangulation<1, 2> tria_1d_in_2d;
    for(auto grid_type_name: grids_types_array)
    {
        tria_1d_in_2d.clear();
        try
        {
            grid_generator(tria_1d_in_2d, grid_type_name);
            tria_1d_in_2d.refine_global(3);
            save(tria_1d_in_2d, grid_type_name + "_1d_in_2d");
        } catch(const MyException& caught){
            cout<<"Got :\" " << caught.what() << "\"" <<endl;
        }
    }

    Triangulation<2> tria_2d;
    for(auto grid_type_name: grids_types_array)
    {
        tria_2d.clear();
        try
        {
            grid_generator(tria_2d, grid_type_name);
            tria_2d.refine_global(3);
            save(tria_2d, grid_type_name + "_2d");
        } catch(const MyException& caught){
            cout<<"Got :\" " << caught.what() << "\"" <<endl;
        }
    }

    Triangulation<2, 3> tria_2d_in_3d;
    for(auto grid_type_name: grids_types_array)
    {
        tria_2d_in_3d.clear();
        try
        {
            grid_generator(tria_2d_in_3d, grid_type_name);
            tria_2d_in_3d.refine_global(3);
            save(tria_2d_in_3d, grid_type_name + "_2d_in_3d");
        } catch(const MyException& caught){
            cout<<"Got :\" " << caught.what() << "\"" <<endl;
        }
    }

    Triangulation<3> tria_3d;
    for(auto grid_type_name: grids_types_array)
    {
        tria_3d.clear();
        try
        {
            grid_generator(tria_3d, grid_type_name);
            tria_3d.refine_global(3);
            save(tria_3d, grid_type_name + "_3d");
        } catch(const MyException& caught){
            cout<<"Got :\" " << caught.what() << "\"" <<endl;
        }
    }

    //step - 2

    //Mesh generation
    Triangulation<2> tria_shell;
    grid_generator(tria_shell, "hyper_shell");
    save(tria_shell, "hyper_shell_2d");
    cout << tria_shell;

    //Sparsity patterns and distribution of dofs
    distribute_dofs(tria_shell, renumbering_type, 1, "sparsity_pattern_1.svg");
    distribute_dofs(tria_shell, renumbering_type, 2, "sparsity_pattern_2.svg");
    distribute_dofs(tria_shell, renumbering_type, 3, "sparsity_pattern_3.svg");

    //step - 3
    for(int renumbering_type = (int)none; renumbering_type <= (int)subdomain_wise; ++renumbering_type)
        for(auto grid_type_name: grids_types_array)
        {
            try
            {
                cout << "grid type: "<< grid_type_name << " renumbering type: " << (renumberings)renumbering_type << endl;

                LaplaceEquationSolver<2, 2> a;
                a.run(grid_type_name, (renumberings)renumbering_type, 
                    "sol_ren_type_" + to_string(renumbering_type) + "_mesh_type_" + grid_type_name);
            }
            catch(const MyException& caught)
            {
                cout<<"Got :\" " << caught.what() << "\"" <<endl;
            }
        }

    //solve laplace on all these meshesh.
    //how to set different boundary id?
    
    return 0;
}