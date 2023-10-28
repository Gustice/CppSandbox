/**
 * @file Property.h
 * @author Gustice
 * @brief C#-like property template for more convenient getter-setter notation
 * @date 2023-10-28
 *
 * @copyright Copyright (c) 2023
 */
#pragma once

template <typename T> class PropertyRW {
  private:
    T &_value;

  public:
    PropertyRW(T &value) : _value(value) {}
    PropertyRW<T> &operator=(const T &val) {
        _value = val;
        return *this;
    };
    /*explicit??*/ operator const T &() const {
        return _value;
    };
};
