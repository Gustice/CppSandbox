#include "string.h"

#include "LegacyModule.h"

static int _variable = 0;
static const int _const = 0;

static int _array[4] = {1, 2, 3, 4};
static const int _constArray[4] = {1, 2, 3, 4};

void LgcyFunction_Pointer2Variable(int *var) {
    printf("Call of : %s\n", __PRETTY_FUNCTION__);
    int *pToVar = var;
    int cOfVar = *var;
    printf("    Pointer p = 0x%p to value v = %d \n", pToVar, cOfVar);
    int newVar = *var * 16;
    *var = newVar;
    printf("    Variable after '*= 16' operation: value v = %d \n", *var);
    
    int *pToNextVar = ++var;
    int cOfNextVar = *pToNextVar;
    printf("    Pointer p = 0x%p to next value v = %d \n", (pToNextVar), (cOfNextVar) );

    printf("    => All Pointer operations work just fine \n");
}

void LgcyFunction_Pointer2Const(int * const var) {
    printf("Call of : %s\n", __PRETTY_FUNCTION__);
    int *pToVar = var;
    int cOfVar = *var;
    printf("    Pointer p = 0x%p to value v = %d \n", pToVar, cOfVar);
    int newVar = *var * 16;
    *var = newVar;
    printf("    Variable after '*= 16' operation: value v = %d \n", *var);
    
    printf("    Note: '++var' wont work\n");
    int *pToNextVar = var + 1;
    int cOfNextVar = *pToNextVar;
    printf("        But 'nVar = var + 1' works just fine:\n");
    printf("        Pointer p = 0x%p to value v = %d \n", (pToNextVar), (cOfNextVar) );
}

void LgcyFunction_ConstPointer2Variable(int const * var)
{
    printf("Call of : %s\n", __PRETTY_FUNCTION__);
    printf("    Note: cannot assign pointer to mutable 'int *pToVar' \n");
    int const *pToVar = var;
    int cOfVar = *var;
    printf("    Pointer p = 0x%p to value v = %d \n", pToVar, cOfVar);
    int newVar = *var * 16;
    printf("    Note: cannot variable with new value '*var = newVar' \n");
    
    int const *pToNextVar = ++var;
    int cOfNextVar = *pToNextVar;
    printf("    Pointer p = 0x%p to next value v = %d \n", (pToNextVar), (cOfNextVar) );

    printf("    => All Pointer operations work just fine \n");
}

void LgcyFunction_ConstPointer2Const(int const * const var)
{
    printf("Call of : %s\r\n", __PRETTY_FUNCTION__);
    printf("    Note: cannot assign pointer to mutable 'int *pToVar' \n");
    int const *pToVar = var;
    int cOfVar = *var;
    printf("    Pointer p = 0x%p to value v = %d \n", pToVar, cOfVar);
    int newVar = *var * 16;
    printf("    Note: cannot variable with new value '*var = newVar' \n");
    
    printf("    Note: '++var' wont work\n");
    int const *pToNextVar = var + 1;
    int cOfNextVar = *pToNextVar;
    printf("        But 'nVar = var + 1' works just fine:\n");
    printf("        Pointer p = 0x%p to value v = %d \n", (pToNextVar), (cOfNextVar) );
}

/**
 * @brief 
 * 
 */
void Lgcy_RunAllFunctionCalls(void)
{
    printf("Running of All Legacy-Methods : %s\r", __PRETTY_FUNCTION__);

    LgcyFunction_Pointer2Variable(&_array[0]);
    //LgcyFunction_Pointer2Variable(&_constArray[0]);
    printf("    Note: 'LgcyFunction_Pointer2Variable' can only be called with mutable values\n");
    
    memcpy(_array, _constArray, sizeof(_array));
    
    LgcyFunction_Pointer2Const(&_array[0]);
    memcpy(_array, _constArray, sizeof(_array));
    
    LgcyFunction_ConstPointer2Variable(&_array[0]);
    memcpy(_array, _constArray, sizeof(_array));
    
    LgcyFunction_ConstPointer2Const(&_array[0]);
    memcpy(_array, _constArray, sizeof(_array));

    printf("Using instantiated class\n");
    int value = 11;
    auto obj = LegacyModule(&value);
    value++;
    obj.ShowExternalValue();
}