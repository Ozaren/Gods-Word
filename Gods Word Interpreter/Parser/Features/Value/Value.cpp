#include "Value.h"
#include "../Type/Type.h"
#include "../Type/DefaultTypes.h"

using namespace std;
using namespace GWI;

Value::Value(PtrType _type)
    : type(_type) {
    // initialize memory

    const ColType types(type->getDynamicValueTypes());

    for (PtrType t : types) {
        if (t == def_type::BOOL) {
            memory.add_val((int)VarTypes::BOOLEAN);
            memory.add_val<bool>(false);
        }
        else if (t == def_type::SINT) {
            memory.add_val((int)VarTypes::SIGNED_INTEGER);
            memory.add_val<int>(0);
        }
        else if (t == def_type::UINT) {
            memory.add_val((int)VarTypes::UNSIGNED_INTEGER);
            memory.add_val<unsigned int>(0);
        }
        else if (t == def_type::FLOT) {
            memory.add_val((int)VarTypes::FLOAT);
            memory.add_val<double>(0);
        }
        else if (t == def_type::CHAR) {
            memory.add_val((int)VarTypes::CHARACTER);
            memory.add_val<char>(0);
        }
        else if (t == def_type::STRN) {
            memory.add_val((int)VarTypes::STRING);
            memory.add_val<string>("");
        }
        else {
            memory.add_val((int)VarTypes::VARIABLE);
            memory.add_val<PtrValue>(nullptr);
        }
    }
}
