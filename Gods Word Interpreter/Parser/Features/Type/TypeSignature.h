#ifndef __GWI_PARSER_FEATURES_TYPE__TYPE_SIGNATURE_H_
#define __GWI_PARSER_FEATURES_TYPE__TYPE_SIGNATURE_H_

#include <string>

#include "../Pointers.h"

__START_NAMESPACE__

class TypeSignature {
    friend Type;
public:
    const std::string full_name;
    const std::string name;
    const std::string group;

    TypeSignature(std::string name, std::string group);
    ~TypeSignature() {}
    const Type* bound_to() const;

private:
    Type *link_type;
};

__END_NAMESPACE__

#endif