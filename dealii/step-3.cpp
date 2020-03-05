#include "step-3.hpp"

namespace step_3{

    void run()
    {
        for(auto grid_type_name: grids_types_array())
        {
            cout << endl << "grid type: "<< grid_type_name << endl << endl;

            try
            {
                LaplaceEquationSolver<2, 2> a;
                a.run(grid_type_name, cuthill_McKee, 
                    "sol_mesh_type_" + grid_type_name + "_2d");
            }
            catch(const MyException& caught)
            {
                cout<<"Got :\" " << caught.what() << "\"" <<endl;
            }

            try
            {
                if (grid_type_name.compare("concentric_hyper_shells") == 0)
                    throw MyException("concentric_hyper_shells grid gives error in 3d");
                LaplaceEquationSolver<3, 3> a;
                a.run(grid_type_name, cuthill_McKee, 
                    "sol_mesh_type_" + grid_type_name + "_3d");
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
                a.run("hyper_cube", cuthill_McKee, func_num, "trivial_function_solution" + to_string(func_num) );
            }
            catch(const MyException& caught)
            {
                cout<<"Got :\" " << caught.what() << "\"" <<endl;
            }
    }
}