#ifndef __GWI_PARSER_PARTS_TYPE__DEFUALT_TYPES_H__
#define __GWI_PARSER_PARTS_TYPE__DEFUALT_TYPES_H__

#include <memory>

#include "Type.h"

namespace GWI {
    struct def_type {
        static const TypeP BOOLEAN;
        static const TypeP INT;
        static const TypeP UINT;
        static const TypeP FLOAT;
        static const TypeP CHAR;
        static const TypeP STRING;
    };
}

#endif
