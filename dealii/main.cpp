#include "step-1.hpp"
#include "step-2.hpp"
#include "step-3.hpp"

#include <map>

int main(void)
{
    step_1_main();//WTF why when I comment out this, error with std11 occur
    //step_2_main();
    step_3_main();
    
    return 0;
}