#include "module.h"
#include "stdio.h"

void Eval_Module_ModuleGlobal(int i)
{
    printf("Potential global call: '%s' with param `%d`\r\n", __PRETTY_FUNCTION__, i);
}

static void Eval_Module_ModuleLocal(int i)
{
    printf("Potential global call: '%s' with param `%d`\r\n", __PRETTY_FUNCTION__, i);
}

void Eval_Module_ExternalGlobal(int i)
{
    printf("External global call: '%s' with param `%d`\r\n", __PRETTY_FUNCTION__, i);
    printf("Also calling some local defined functions \r\n");
    
    Eval_Module_ModuleGlobal(11);
    Eval_Module_ModuleLocal(12);
}

