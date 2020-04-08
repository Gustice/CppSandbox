#if !defined(MODULE_H)
#define MODULE_H

class Module
{
private:
    int _iField;
    int _iField2;
        
public:
    void Eval_HDefinedSetter(int value){ _iField = value; }
    int Eval_HDefinedGetter(void){ return _iField; }

    void Eval_CppImplementedSetter(int value);
    int Eval_CppImplementedGetter(void);
};

#endif // MODULE_H
