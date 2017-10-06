#ifndef __GWI_PARSER_FEATURES_VALUE__VALUE_H_
#define __GWI_PARSER_FEATURES_VALUE__VALUE_H_

#include "../Pointers.h"

#include "../Memory/linear_memory_buffer.h"

__START_NAMESPACE__
    enum VarTypes { UNKNOWN = -1, BOOLEAN, SIGNED_INTEGER, UNSIGNED_INTEGER, FLOAT, CHARACTER, STRING, VARIABLE };

    class Value {
    public:
        const PtrType type;

    private:
        linear_memory_buffer memory;
    };
__END_NAMESPACE__

#endif