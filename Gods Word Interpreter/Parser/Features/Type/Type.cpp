#include "Type.h"

#include "TypeSignature.h"

using namespace std;
__USE_NAMESPACE__

Type::Type(ConstTypeSignature _signature, ColPtrVariable _type_variables,
    ColConstTypeSignature _object_variable_types, size_t _known_size)
    : signature(_signature), type_variables(_type_variables),
    object_variable_types(_object_variable_types), known_size(_known_size) {
    
}

size_t Type::get_object_size() {
    if (known_size == 0) {
        size_t size = 0;

        for (ConstTypeSignature sig: object_variable_types) {
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
