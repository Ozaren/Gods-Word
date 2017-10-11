#ifndef __GWI_PARSER_FEATURES_TYPE__DEFUALT_TYPE_H_
#define __GWI_PARSER_FEATURES_TYPE__DEFUALT_TYPE_H_

#include <string>

#include "../Pointers.h"

__START_NAMESPACE__

struct def_type {
    static const PtrType BOOL;
    static const PtrType SINT;
    static const PtrType UINT;
    static const PtrType FLOT;
    static const PtrType CHAR;
    static const PtrType STRN;
};

__END_NAMESPACE__

#endif