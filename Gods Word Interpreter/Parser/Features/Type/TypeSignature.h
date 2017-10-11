#ifndef __GWI_PARSER_FEATURES_TYPE__TYPE_SIGNATURE_H_
#define __GWI_PARSER_FEATURES_TYPE__TYPE_SIGNATURE_H_

#include <string>

#include "../Pointers.h"

__START_NAMESPACE__

class TypeSignature {
public:
    std::string name;
    std::string group;

    TypeSignature(std::string name, std::string group);
    ~TypeSignature() {}
    void bind(Type *type);
    const Type* bound_to() const;

private:
    Type *link_type;
};

__END_NAMESPACE__

#endif