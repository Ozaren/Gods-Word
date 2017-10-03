#ifndef __GWI_PARSER_PARTS_TYPE__DEFUALT_TYPES_H__
#define __GWI_PARSER_PARTS_TYPE__DEFUALT_TYPES_H__

#include <string>

#include "Type.h"

namespace GWI {
    struct def_type {
        static const Type::pointer BOOLEAN;
        static const Type::pointer INT;
        static const Type::pointer UINT;
        static const Type::pointer FLOAT;
        static const Type::pointer CHAR;
        static const Type::pointer STRING;
    };
}

#endif
