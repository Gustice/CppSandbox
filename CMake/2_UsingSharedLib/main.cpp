#include <stdio.h>
#include <string>
#include <iostream>

#include "statLib.h"
#include "dynLib.h"

int main(int argc, char const *argv[])
{
    printf("########################\n");
    printf("Entering main ... \n");
    printf("########################\n");

    printf("## Static Library is used \n");
    Lib_Helper();
    
    printf("## Dynamic-Library is used \n");
    Dyl_InitCore();
        
    return 0;
}
