#ifndef __GWI_PARSER_FEATURES_TYPE__TYPE_H_
#define __GWI_PARSER_FEATURES_TYPE__TYPE_H_

#include <string>

#include "../Pointers.h"

__START_NAMESPACE__

class Type {
public:
    const ConstTypeSignature signature;

    Type(PtrTypeSignature signature, ColPtrVariable type_variables,
        ColConstTypeSignature object_variables, size_t known_size = 0);
    ~Type() { }

    size_t get_object_size();

    ColPtrVariable& get_type_variables();
    const ColConstTypeSignature& get_object_variable_types() const;

private:
    ColPtrVariable type_variables;
    ColConstTypeSignature object_variable_types;

    size_t known_size;
};

__END_NAMESPACE__

#endif