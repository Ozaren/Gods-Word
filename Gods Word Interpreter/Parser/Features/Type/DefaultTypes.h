#ifndef __GWI_PARSER_FEATURES_TYPE__DEFUALT_TYPE_H_
#define __GWI_PARSER_FEATURES_TYPE__DEFUALT_TYPE_H_

#include "../Pointers.h"

namespace GWI {
    struct def_type {
        const static PtrType BOOL; // boolean
        const static PtrType SINT; // signed int
        const static PtrType UINT; // unsigned int
        const static PtrType FLOT; // float
        const static PtrType CHAR; // character
        const static PtrType STRN; // string
    };
}

#endif
