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

#if STEP == 1 
#include "module.h"
#endif

#include "stdio.h"

void Eval_GlobalFun(int i)
{
    printf("Potential global call: '%s' with param `%d`\r\n", __PRETTY_FUNCTION__, i);
}

static void Eval_LocalStaticFun(int i)
{
    printf("Local call: '%s' with param `%d`\r\n", __PRETTY_FUNCTION__, i);
}

int main(int argc, char const *argv[])
{
    printf("Call of Main: %s \r\n", __PRETTY_FUNCTION__);
        
    Eval_GlobalFun(1);
    Eval_LocalStaticFun(2);

#if STEP == 1
    Eval_Module_ExternalGlobal(10);
#endif

    /* code */
    return 0;
}
