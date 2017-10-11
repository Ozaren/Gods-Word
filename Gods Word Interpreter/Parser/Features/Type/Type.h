#ifndef __GWI_PARSER_FEATURES_TYPE__TYPE_H_
#define __GWI_PARSER_FEATURES_TYPE__TYPE_H_

#include <string>

#include "../Pointers.h"

__START_NAMESPACE__

class Type {
public:
    const ConstTypeSignature signature;
    const size_t id;

    Type(PtrTypeSignature signature, ColPtrVariable type_variables,
        ColConstTypeSignature object_variables, size_t known_size = 0);
    ~Type() { }

    size_t get_object_size();

    ColPtrVariable& get_type_variables();
    const ColConstTypeSignature& get_object_variable_types() const;

private:
    static size_t next_id;

    ColPtrVariable type_variables;
    ColConstTypeSignature object_variable_types;

    size_t known_size;
};

__END_NAMESPACE__

bool operator==(const __NAMESPACE__::Type &t1, const __NAMESPACE__::Type &t2) {
    return t1.id == t2.id;
}

bool operator==(const __NAMESPACE__::PtrType &t1, const __NAMESPACE__::PtrType &t2) {
    return operator==(*t1, *t2);
}

bool operator!=(const __NAMESPACE__::Type &t1, const __NAMESPACE__::Type &t2) {
    return !operator==(t1, t2);
}

bool operator!=(const __NAMESPACE__::PtrType &t1, const __NAMESPACE__::PtrType &t2) {
    return !operator==(t1, t2);
}

#endif