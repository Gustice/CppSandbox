#include "module.h"

#include <iostream>
#include "stdio.h"

void Eval_GlobalFun(int i)
{
    printf("Potential global call: '%s' with param `%d`\r\n", __PRETTY_FUNCTION__, i);
}

static void Eval_LocalStaticFun(int i)
{
    printf("Local call: '%s' with param `%d`\r\n", __PRETTY_FUNCTION__, i);
}

int main(int argc, char const *argv[])
{
    std::cout << "Call of Main: " << __PRETTY_FUNCTION__ << std::endl;
    
    Eval_GlobalFun(1);
    Eval_LocalStaticFun(2);

    Eval_Module_ExternalGlobal(10);
    /* code */
    return 0;
}
