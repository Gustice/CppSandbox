/**
 * @file LegacyModule.h
 * @author Gustice
 * @brief Demonstration of ordinary pointer
 * @version 0.1
 * @date 2020-09-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#if !defined(LEGACYMODULE_H)
#define LEGACYMODULE_H

#include "stdio.h"
void Lgcy_RunAllFunctionCalls(void);

class LegacyModule
{
public:
    LegacyModule(int * ref) {eValue = ref;};
    ~LegacyModule() {};

    void ShowExternalValue() {
            printf("    ReferenceValue is %d \n", *eValue);
    };

private:
    int _iValue;
    int *eValue;
};


#endif // LEGACYMODULE_H
