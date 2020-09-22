/**
 * @file ReferencedModule.h
 * @author Gustice
 * @brief Demonstration of references
 * @version 0.1
 * @date 2020-09-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#if !defined(REFERENCEDMODULE_H)
#define REFERENCEDMODULE_H

#include "stdio.h"

void Ref_RunAllFunctionCalls(void);

class ReferencedModule
{
public:
    ReferencedModule(int &ref, int *refA) : eValue(ref), eValueA(*refA) {};
    ~ReferencedModule() {};

    void ShowExternalValues() {
            printf("    ReferenceValue is %d \n", eValue);
            printf("    Alternative ReferenceValue is %d \n", eValueA);
    };

private:
    int _iValue;
    int &eValue;
    int &eValueA;
};


#endif // REFERENCEDMODULE_H
