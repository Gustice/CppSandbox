/**
 * @file main.c
 * @author Gustice
 * 
 * @brief C-Programm with different calls to analyze effect of modifiers on 
 *      compiled output.
 *      Compilation and source-dumps are generated with 'runMe.sh'.
 * @version 0.1
 * @date 2020-04-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

// #if STEP == 1
#include "FunCall.h"
// #endif

#include "stdio.h"


/* Main to call all functions */
int main(int argc, char const *argv[])
{
    printf("Call of Main (%s) \r\n", __PRETTY_FUNCTION__);

    Eval_Module_FunCall();

    /* code */
    return 0;
}
