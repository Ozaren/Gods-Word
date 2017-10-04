#ifndef __GWI_PARSER_PARTS_TYPE__DEFUALT_TYPES_H__
#define __GWI_PARSER_PARTS_TYPE__DEFUALT_TYPES_H__

#include <string>

#include "Type.h"

namespace GWI {
    struct def_type {
        static const Type BOOLEAN;
        static const Type INT;
        static const Type UINT;
        static const Type FLOAT;
        static const Type CHAR;
        static const Type STRING;
    };
}

#endif
