#ifndef __GWI_PARSER_FEATURES_VALUE__VALUE_H_
#define __GWI_PARSER_FEATURES_VALUE__VALUE_H_

#include <string>

#include "../Pointers.h"

#include "../Memory/linear_memory_buffer.h"

namespace GWI {
    enum VarTypes { UNKNOWN = -1, BOOLEAN, SIGNED_INTEGER, UNSIGNED_INTEGER, FLOAT, CHARACTER, STRING, VARIABLE };

    union VarValue_value {
        bool b_val;
        int i_val;
        unsigned int ui_val;
        double f_val;
        char c_val;
        std::string s_val;
        PtrValue v_val;
    };

    struct VarValue {
        const VarValue_value &val;
        const VarTypes type;
    };

    class Value {
    public:
        Value(PtrType type);

        const PtrType type;

    private:
        linear_memory_buffer memory;
    };
}

#endif