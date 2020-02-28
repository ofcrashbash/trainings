#include "step-3.hpp"

void step_3_main()
{
    for(int renumbering_type = (int)none; renumbering_type <= (int)random_renumbering; ++renumbering_type)
        for(auto grid_type_name: grids_types_array())
        {
            cout << "grid type: "<< grid_type_name << " renumbering type: " << (renumberings)renumbering_type << endl;

            try
            {
                LaplaceEquationSolver<2, 2> a;
                a.run(grid_type_name, (renumberings)renumbering_type, 
                    "sol_ren_type_" + to_string(renumbering_type) + "_mesh_type_" + grid_type_name);
            }
            catch(const MyException& caught)
            {
                cout<<"Got :\" " << caught.what() << "\"" <<endl;
            }
        }

    for(int func_num = 0; func_num <= 5; ++func_num)
        try
        {
            TrivialFunctionSolver<2, 2> a;
            a.run("hyper_cube", none, func_num, "trivial_function_solution" + to_string(func_num) );
        }
        catch(const MyException& caught)
        {
            cout<<"Got :\" " << caught.what() << "\"" <<endl;
        }
}