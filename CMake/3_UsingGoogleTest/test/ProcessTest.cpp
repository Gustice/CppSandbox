#include <iostream>
#include "MyProcess.h"

int main(int argc, char const *argv[])
{
    uint32_t inVar = 2;
    uint32_t outVar = 0;
    bool res = Pc_Evaluate(inVar, &outVar);
    if (res == false && outVar == 4)
        std::cout << "## Test Successful" << std::endl;
    else
        std::cout << "## Test Failed !!!!!!!!!!!" << std::endl;
    return 0;
}
