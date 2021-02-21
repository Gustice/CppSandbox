/**
 * @file dynLib.cpp
 * @author Gustice
 * @brief Dynamic Library Implementation
 * @version 0.1
 * @date 2020-10-04
 * 
 * @copyright Copyright (c) 2020
 */

#include "util.h"
#include "dynLib.h"

#include <stdio.h>

OpStatus InitCore(){
    printf("    ## DynLib: Static initialized \n");
    return OpStatus::Initialized;
}

OpStatus StartCore(){
    printf("    ## DynLib: Core stated \n");
    int num = Util_GenNumber();
    if (num >= 0) {
        return OpStatus::Initialized;
    }
    
    return OpStatus::Invalid;
}