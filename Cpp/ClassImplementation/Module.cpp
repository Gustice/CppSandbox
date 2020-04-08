#include "Module.h"

void Module::Eval_CppImplementedSetter(int value)
{
    _iField2 = value;
}

int Module::Eval_CppImplementedGetter(void)
{
    return _iField2;
}