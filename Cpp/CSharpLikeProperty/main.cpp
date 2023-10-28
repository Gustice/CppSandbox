/**
 * @file main.c
 * @author Gustice
 * @brief C++-Programm to demonstrate C#-properties-syntax
 * @date 2020-04-04
 * 
 * @copyright Copyright (c) 2020
 */

#include <stdio.h>
#include "Module.h"

int main(int argc, char const *argv[])
{
    printf("Call of Main: %s \n", __PRETTY_FUNCTION__);
    
    Module module;
    printf("Initial value of variables: property=%d / field=%d\n", 
    (int)module.Property, module.getField());

    // Usage of typical getter/setter
    module.setField(module.getField() +1);
    
    // Usage of properties
    module.Property = module.Property +1 ;

    printf("Final result of variables: property=%d / field=%d", 
    (int)module.Property, module.getField());

    return 0;
}

// Conclusion so far:
//   Syntax is more pleasant but the implicit conversion does not work always for you
//   However implicit conversion aren't desired anyways