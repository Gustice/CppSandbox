#include "MyProcess.h"
#include <algorithm>

static const uint32_t maxOut = 100;

bool Pc_Evaluate(uint32_t varIn, uint32_t * varOut)
{
    uint32_t temp = varIn * 2;
    bool overflow = temp > maxOut;
    temp = std::min(maxOut, temp);
    *varOut = temp;
    return overflow;
}