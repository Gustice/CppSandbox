/**
 * @file dynLib.h
 * @author Gustice
 * @brief Dynamic Library
 * @version 0.1
 * @date 2020-10-04
 * 
 * @copyright Copyright (c) 2020
 */

#pragma once

enum OpStatus
{
    Invalid,
    Initialized,
    Running,
};

OpStatus InitCore();
OpStatus StartCore();