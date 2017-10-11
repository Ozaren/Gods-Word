#include "Type.h"

#include "TypeSignature.h"
#include "../Variable/Variable.h"

using namespace std;
__USE_NAMESPACE__

size_t Type::next_id = 0;

Type::Type(PtrTypeSignature _signature, ColPtrVariable _type_variables,
    ColConstTypeSignature _object_variable_types, size_t _known_size)
    : signature(_signature->link_type == nullptr ? _signature : nullptr), type_variables(_type_variables),
    object_variable_types(_object_variable_types), known_size(_known_size), id(next_id++) {
    if (_signature->link_type == nullptr)
        _signature->link_type = this;
    else
        PRINT_ERROR("Link Error", "Cannot link to bound signature")
}

size_t Type::get_object_size() {
    if (known_size == 0) {
        size_t size = 0;

        for (ConstTypeSignature sig : object_variable_types) {
            size_t ks = sig->bound_to()->known_size;
            if (ks == 0) {
                size += sizeof(ConstVariable);
            }
            else {
                size += ks;
            }
        }

        return size;
    }
    else {
        return known_size;
    }
}

ColPtrVariable& Type::get_type_variables() {
    return type_variables;
}

const ColConstTypeSignature& Type::get_object_variable_types() const {
    return object_variable_types;
}
