/**
 * @file Module.h
 * @author Gustice
 * @brief Module definition that utilizes C#-like-property
 * @date 2023-10-28
 * 
 * @copyright Copyright (c) 2023
 */
#ifndef MODULE_H
#define MODULE_H

#include "Property.h"

class Module
{
private:
    int _property {};
    int _field {};
        
public:
    // Property instance
    PropertyRW<int> Property;
    
    Module() : Property(_property) {}
    
    // typical getter/setter
    void setField(int value){ _field = value; }
    int getField(void) const { return _field; } 
};

#endif // MODULE_H
