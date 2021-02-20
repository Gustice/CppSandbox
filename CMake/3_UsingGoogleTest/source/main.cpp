#include <iostream>
#include <string>
#include <stdio.h>
#include <stdint.h>

#include "MyProcess.h"

int main(int argc, char const *argv[])
{
    std::cout << "### Starting Main" << std::endl;
    
    uint32_t values[] = {2, 4, 8, 16, 32, 64};

    for (size_t i = 0; i < sizeof(values)/sizeof(values[0]); i++)
    {
        uint32_t out;
        if (Pc_Evaluate(values[i], &out) == false)
            printf("    Calling Module with %d yields %d \n", values[i], out);
        else
            printf("    Calling Module with %d yields %d with overflow \n", values[i], out);
    }
    
    return 0;
}
