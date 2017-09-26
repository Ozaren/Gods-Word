#ifndef __GWI_PARSER_PARTS_VARIABLES__VARIABLE_H__
#define __GWI_PARSER_PARTS_VARIABLES__VARIABLE_H__

#include <string>

#include "../Type/Type.h"

#define VMB_NONE 0 // Reference
#define VMB_REF 1 // Reference
#define VMB_CONST 2 // Constant
#define VMB_PUB 4 // public/private
#define VMB_prot 8 // protected

class Variable {
public:
    const std::string name;
    const Type &type;
    const uint8_t mod;

    Variable(std::string name, const Type &type, void *value, uint8_t mod);

    template<typename ValType>
    bool setValue(ValType _value) {
        if (!hasMod(VMB_CONST) && _value.type == type) {
            this->value = (void*)(_value.getValue());
            return true;
        }
        else {
            return false;
        }
    }

    const void* getValue() const { return value; }
    bool hasMod(uint8_t mod) const;
private:
    void *value;
};

#endif