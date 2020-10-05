/**
 * @brief Main.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */


#include <stdio.h>
#include <string>

#include "process.h"
#include "core.h"

int main(int argc, char const *argv[])
{
    printf("########################\n");
    printf("Entering main ... \n");
    printf("########################\n");

    if (InitCore() == OpStatus::Initialized) {
        (void)StartCore();
    }

    printf("Returned from call %d \n ", Prc_ProcessCall(1));
    
    return 0;
}
