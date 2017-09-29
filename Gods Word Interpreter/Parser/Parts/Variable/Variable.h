#ifndef __GWI_PARSER_PARTS_VARIABLE__VARIABLE_H__
#define __GWI_PARSER_PARTS_VARIABLE__VARIABLE_H__

#include "../Type/Type.h"

/*
#define boolVariableP GWI::pointer<bool>::VariableP
#define intVariableP GWI::pointer<int>::VariableP
#define uintVariableP GWI::pointer<unsigned int>::VariableP
#define floatVariableP GWI::pointer<double>::VariableP
#define charVariableP GWI::pointer<char>::VariableP
#define stringVariableP GWI::pointer<std::string>::VariableP

#define make_boolVariableP new GWI::Variable<bool>
#define make_intVariableP new GWI::Variable<int>
#define make_uintVariableP new GWI::Variable<unsigned int>
#define make_floatVariableP new GWI::Variable<double>
#define make_charVariableP new GWI::Variable<char>
#define make_stringVariableP new GWI::Variable<std::string>
*/

namespace GWI {
    typedef void* var_val;
    class Variable {
    public:
        Variable(const TypeP &_type, var_val _value)
            : type(_type), value(_value) {

        }

        const TypeP type;

        Variable& operator=(var_val &val) { value = val; }

        bool operator==(const Variable &v) const { return *v.type == *type && v.value == value; }
        bool operator!=(const Variable &v) const { return !operator==(v); }
        bool operator==(const Variable *v) const { return operator==(v); }
        bool operator!=(const Variable *v) const { return !operator==(v); }

        /*
        template<typename T>
        bool setValue(T val) {
            if (val.type == type)
                value = (var_val)val.getValue();
        }
        */
        bool setValue(void *val) {
            value = val;
        }

        var_val getValue() const { return value; }
    private:
        var_val value;
    };

    typedef std::shared_ptr<Variable> VariableP;
}
#endif