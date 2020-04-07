#include "FunCall.h"
#include "stdio.h"

/* Simple function calls */
static void Eval_Fun_Int(int i)
{
    printf("Call of '%s' with param `%d`\r\n", __PRETTY_FUNCTION__, i);
}

static void Eval_Fun_IntInt(int i, int j)
{
    printf("Call of '%s' with param `%d and %d`\r\n", __PRETTY_FUNCTION__, i, j);
}

static int Eval_Fun_Int_RetInt(int i)
{
    printf("Call of '%s' with param `%d`\r\n", __PRETTY_FUNCTION__, i);
    return i * 2;
}

void Eval_Module_FunCall(void)
{
    printf("Function Calls Module called (%s) \r\n", __PRETTY_FUNCTION__);
    
    Eval_Fun_Int(11);
    Eval_Fun_IntInt(12,13);
    int i = Eval_Fun_Int_RetInt(14);
}

