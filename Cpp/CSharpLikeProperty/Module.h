#if !defined(MODULE_H)
#define MODULE_H

#include "Property.h" // Definition of Property

class Module
{
private:
    int _property;
    int _iField;
    int _iField2;
        
public:
    /* Initialization of Property */
    Module() : Property(_property) {};
    void Eval_HDefinedSetter(int value){ _iField = value; }
    int Eval_HDefinedGetter(void){ return _iField; }

    /* Implementation of Property */
    PropertyRW<int> Property;

    void Eval_CppImplementedSetter(int value);
    int Eval_CppImplementedGetter(void);
};

#endif // MODULE_H
