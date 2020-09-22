#include "LegacyModule.h"
#include "ReferencedModule.h"

#include "stdio.h"

int main(int argc, char const *argv[])
{
    printf("####################\n");
    printf("## Running Pointer based functions ");
    Lgcy_RunAllFunctionCalls();
    
    printf("####################\n");
    printf("## Running Referenced based functions ");
    Ref_RunAllFunctionCalls();
    return 0;
}
