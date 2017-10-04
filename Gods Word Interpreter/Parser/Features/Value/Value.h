#ifndef __GWI_PARSER_FEATURES_VALUE__VALUE_H_
#define __GWI_PARSER_FEATURES_VALUE__VALUE_H_

#include <memory>
#include <vector>

#include "../Pointers.h"

#include "../Memory/linear_memory_buffer.h"

namespace GWI {
    enum VarTypes { UNKNOWN = -1, BOOLEAN, SIGNED_INTEGER, UNSIGNED_INTEGER, FLOAT, CHARACTER, STRING, VARIABLE };

    class Value {
    public:
        const PtrType type;

    private:
        linear_memory_buffer memory;
    };
}

#endif