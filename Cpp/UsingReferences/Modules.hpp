/**
 * @file LegacyModule.h
 * @author Gustice
 * @brief Class helper for demonstration
 * @version 0.1
 * @date 2020-09-15
 *
 * @copyright Copyright (c) 2020
 */

#ifndef MODULES_H
#define MODULES_H

#include "MicroFormatter.hpp"

void Lgcy_RunAllFunctionCalls(void);

class LegacyModule {
  public:
    LegacyModule(int *ref) {
        // this variable may be initialized in constructor body
        // however still better to initialize it in member init list
        _pValue = ref;
    };
    ~LegacyModule() = default;

    std::string showTypeInfo() {
        return fmt.format("var origin@%p", _pValue);
    };

  private:
    int *_pValue;
};

class ReferencedModule {
  public:
    ReferencedModule(int &ref) : _value(ref){};
    ~ReferencedModule() = default;

    std::string showTypeInfo() {
        return fmt.format("var origin@%p", &_value);
    };

  private:
    int &_value;
};

#endif // MODULES_H
