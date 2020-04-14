/**
 * @file main.c
 * @author Gustice
 * 
 * @brief C++-Programm with different calls to analyze effect of modifiers on 
 *      compiled output.
 *      Compilation and source-dumps are generated with 'runMe.sh'.
 * @version 0.1
 * @date 2020-04-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "stdio.h"
#include "Module.h"

int main(int argc, char const *argv[])
{
    printf("Call of Main: %s \r\n", __PRETTY_FUNCTION__);
    
    int i = 0;
    Module module;
    
    module.Eval_HDefinedSetter(++i);
    i = module.Eval_HDefinedGetter();

    module.Eval_CppImplementedSetter(++i);
    i = module.Eval_CppImplementedGetter();

    /* Usage of Property */
    module.Property = i;
    i = module.Property;

    printf("Final result of variable: %d", i);

    return 0;
}
