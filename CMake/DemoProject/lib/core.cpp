/**
 * @file core.cpp
 * @author Gustice
 * @brief CoreProcessing of Library
 * @version 0.1
 * @date 2020-10-04
 * 
 * @copyright Copyright (c) 2020
 */

#include "util.h"
#include "core.h"

#include <stdio.h>

OpStatus InitCore(){
    printf("    ## Core initialized \n");
    return OpStatus::Initialized;
}

OpStatus StartCore(){
    printf("    ## Core stated \n");
    int num = Util_GenNumber();
    if (num >= 0) {
        return OpStatus::Initialized;
    }
    
    return OpStatus::Invalid;
}