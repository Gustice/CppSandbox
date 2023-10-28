/**
 * @file main.cpp
 * @author Gustice
 * @brief Showing difference in usage of pointers and references
 * @version 0.1
 * @date 2023-10-28
 *
 * @copyright Copyright (c) 2023
 */

#include "MicroFormatter.hpp"
#include "Modules.hpp"

#include <array>
#include <cassert>
#include <iostream>
#if __cplusplus >= 202002L
#include <span>
#endif
#include <stdio.h>
#include <string>

MicroFormatter<512> fmt;

/******************************************************************************/
/**
 * Simple use-cases
 */
namespace simpleVar {

std::string processPointer(int *var) {
    // NOTE: var can be nullptr
    if (var == nullptr) {
        return "nullptr";
    }
    // mutating a variable
    *var = *var + 1;
    return fmt.format("mutating var@%p", var);
}

std::string processReference(int &var) {
    var = var + 1;
    auto *pVar = &var; // still i can get a pointer to memory location
    return fmt.format("mutating var@%p", pVar);
}

std::string processOptionalReference(int *pVar) {
    if (pVar == nullptr) {
        return "nullptr";
    }
    // defined from here
    auto &var = *pVar;
    assert(pVar == &var && "getting pointer from reference leads to old pointer");
    var = var + 1;
    return fmt.format("mutating var@%p", pVar);
}

std::string processConstPointer(int const *const var) {
    // const pointer to const value
    return "";
}

std::string processConstReference(const int &var) {
    // plain const
    return "";
}

std::string processObjectInstance(const std::string &str) {
    // depending on what you are actually going to do with string
    // this is a much optimized approach on passing object instances
    // because it spare copies
    return "";
}

void Demo() {
    int var{};
    auto effect1 = processPointer(&var);
    assert(var == 1 && "Must have been incremented");
    auto effect2 = processReference(var);
    assert(var == 2 && "Must have been incremented");
    auto effect3 = processOptionalReference(&var);

    assert(effect1 == effect2 && "Must mutate same address independent from call type");
    assert(effect2 == effect3 && "Must mutate same address independent from call type");
    // NOTE: Easier syntax with references especially in case const signature
    //   only disadvantage is that optional arguments are impossible in a plain way
}
} // namespace simpleVar

/******************************************************************************/
/**
 * Arrays
 */
namespace arrayVar {

constexpr int N = 4;
using BuffType = std::array<int, N>;

std::string processPointerErrProne(int *var, const int size) {
    // lets ignore nullptr here ...
    // mutating a series
    for (size_t i = 0; i < size; i++) {
        var[i] = i;
    }
    return fmt.format("mutating arr@%p", var);
}

std::string processPointerBetter(int var[N]) {
    // NOTE: However not always possible due to variable sizes
    // lets ignore nullptr here ...
    // mutating a series
    for (size_t i = 0; i < N; i++) {
        var[i] = i;
    }
    return fmt.format("mutating arr@%p", var);
}

std::string processReference(BuffType &var) {
    // NOTE: However not always possible due to variable sizes
    int i{};
    // mutating a series
    for (auto &&v : var) {
        v = i++;
    }
    return fmt.format("mutating arr@%p", &var);
}

std::string processCopyOfArray(BuffType var) {
    int i{};
    for (auto &&v : var) {
        v = i++;
    }
    return fmt.format("mutating arr@%p", &var);
}

#if __cplusplus >= 202002L
std::string processVariableArray(std::span<int> var) {
    int i{};
    for (auto &&v : var) {
        v = i++;
    }
    return fmt.format("mutating arr@%p", var.data());
}
#endif

void resetArray(int var[N]) {
    for (size_t i = 0; i < N; i++) {
        var[i] = 0;
    }
}
void resetArray(BuffType &var) {
    for (auto &&v : var) {
        v = 0;
    }
}

void Demo() {
    int arrL[N]{};
    std::array<int, N> arrM{};

    auto effect1 = processPointerErrProne(arrL, N);
    resetArray(arrL);
    auto effect2 = processPointerBetter(arrL);
    resetArray(arrL);
    auto effect3 = processCopyOfArray(arrM); // no effect on array instance
    auto effect4 = processReference(arrM);
    resetArray(arrM);

    assert(effect1 == effect2 && "Must mutate same address independent from call type");
    assert(effect3 != effect4 && "Must mutate different address on stack because of copy");

#if __cplusplus >= 202002L
    // Old fashioned arrays need to wrapped in span
    auto effectS1 = processVariableArray(std::span{arrL, N});
    resetArray(arrL);
    // Modern array supports array directly
    auto effectS2 = processVariableArray(arrM);
    resetArray(arrM);

    assert(effect1 == effectS1 && "Must mutate same address independent from call type");
    assert(effect4 == effectS2 && "Must mutate same address independent from call type");
#endif

    // NOTE: quite little gain of convenience by using std::array
    //  because often variable array lengths are needed
    //  however std::spans changed this recently to a lot better
}

} // namespace arrayVar

namespace classInstances {

void Demo() {
    int value;
    auto objL = LegacyModule(&value);
    auto objM = ReferencedModule(value);

    auto info1 = objL.showTypeInfo();
    auto info2 = objM.showTypeInfo();

    assert(info1 == info2 && "Must reference the same value");
}
} // namespace classInstances

int main(int argc, char const *argv[]) {
    std::cout << fmt.format("Running simple demo (%s)\n", __PRETTY_FUNCTION__);

    std::cout << "## Simple variables \n";
    simpleVar::Demo();
    std::cout << "## Arrays \n";
    arrayVar::Demo();
    std::cout << "## Instances \n";
    classInstances::Demo();
    return 0;
}
