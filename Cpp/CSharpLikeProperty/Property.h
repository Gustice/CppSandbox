#pragma once

template<typename T>
class PropertyRW 
{
private:
    T& _value;
public:
    PropertyRW(T& value) : _value(value) {}
    PropertyRW<T>& operator = (const T& val) 
    {
        _value = val;
        return *this;
    };
    operator const T&() const { return _value; };
};

