#include "string.h"

#include "ReferencedModule.h"

static int _variable = 0;
static const int _const = 0;

static int _array[4] = {1, 2, 3, 4};
static const int _constArray[4] = {1, 2, 3, 4};

void ReferencedFunction_Reference2Variable(int &var) {
    printf("Call of : %s\n", __PRETTY_FUNCTION__);
    int *pToVar = &var;
    int cOfVar = var;
    printf("    Pointer p = 0x%p to value v = %d \n", pToVar, cOfVar);
    int newVar = var;
    newVar *= 16;
    var = newVar;
    printf("    Variable after '*= 16' operation: value v = %d \n", var);
}

void ReferencedFunction_Reference2Const(const int &var) {
    printf("Call of : %s\n", __PRETTY_FUNCTION__);
    const int *pToVar = &var;
    int cOfVar = var;
    printf("    Note: cannot assign reference to mutable 'int *pToVar' \n");
    printf("    Pointer p = 0x%p to value v = %d \n", pToVar, cOfVar);
    printf("    Note: cannot variable with new value '*var = newVar' \n");
}

void ReferencedFunction_Reference2Array(int (&var)[4] ) {
    printf("Call of : %s\n", __PRETTY_FUNCTION__);
    int *pToVar = &var[0];
    int cOfVar = var[0];
    printf("    Pointer p = 0x%p to value v = %d \n", pToVar, cOfVar);
    printf("    Pointer p = 0x%p to next value v = %d \n", &var[1], var[1]);
    var[0] = var[0] * 16;
    printf("    Variable after '*= 16' operation: value v = %d \n", var[0]);
}

void ReferencedFunction_Reference2ConstArray(const int (&var)[4] ) {
    printf("Call of : %s\n", __PRETTY_FUNCTION__);
    int const *pToVar = &var[0];
    int cOfVar = var[0];
    printf("    Note: cannot assign reference to mutable 'int *pToVar' \n");
    printf("    Pointer p = 0x%p to value v = %d \n", pToVar, cOfVar);
    printf("    Pointer p = 0x%p to next value v = %d \n", &var[1], var[1]);
    //var[0] = var[0] * 16;
    printf("    Note: cannot variable with new value '*var[0] = newVar' \n");
}

void Ref_RunAllFunctionCalls(void)
{
    printf("Running of All Legacy-Methods : %s\r", __PRETTY_FUNCTION__);

    ReferencedFunction_Reference2Variable(_array[0]);
    //ReferencedFunction_Pointer2Variable(&_constArray[0]);
    printf("    Note: 'ReferencedFunction_Pointer2Variable' can only be called with mutable values\n");
    memcpy(_array, _constArray, sizeof(_array));
    
    ReferencedFunction_Reference2Const(_array[0]);
    memcpy(_array, _constArray, sizeof(_array));
    
    ReferencedFunction_Reference2Array(_array);
    memcpy(_array, _constArray, sizeof(_array));
    
    ReferencedFunction_Reference2ConstArray(_array);
    memcpy(_array, _constArray, sizeof(_array));

    printf("Using instantiated class\n");
    int value = 22;
    int valueA = 33;
    auto obj = ReferencedModule(value, &valueA);
    value++;
    valueA++;
    obj.ShowExternalValues();

}