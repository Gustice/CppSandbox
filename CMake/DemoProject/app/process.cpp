/**
 * @file process.cpp
 * @author Gustice
 * @brief Some CppModule-Implementation
 * @version 0.1
 * @date 2020-10-04
 * 
 * @copyright Copyright (c) 2020
 */

#include "process.h"
#include <stdio.h>

int Prc_ProcessCall(int num)
{
    printf("    Process Module is called \n");
    return num++;
}