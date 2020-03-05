#include "step-1.hpp"
#include "step-2.hpp"
#include "step-3.hpp"

#include <map>

int main(void)
{
    try
    {
        step_1_main();//WTF why when I comment out this, error with std11 occur
        //step_2_main();
        step_3::run();
    }
    catch(const exception &exc)
    {
        cerr << endl <<"Exception on processing: " << endl
            << exc.what() << endl << endl;
    }
    catch(...)
    {
        cerr << "Unknown exception" << endl;
        throw;
    }
        
    return 0;
}