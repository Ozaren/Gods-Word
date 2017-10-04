#ifndef __GWI_PARSER_PARTS_VARIABLE__VARIABLE_H__
#define __GWI_PARSER_PARTS_VARIABLE__VARIABLE_H__

// #include <memory>

#include "../Type/Type.h"

namespace GWI {
    typedef void* var_val;
    class Variable {
    public:
        // typedef std::shared_ptr<Variable> pointer;
        
        const Type type;

        Variable(const Type &_type, var_val _value)
            : type(_type), value(_value) {

        }

        Variable& operator=(var_val &val) { value = val; }

        bool operator==(const Variable &v) const { return v.type == type && v.value == value; }
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
}
#endif