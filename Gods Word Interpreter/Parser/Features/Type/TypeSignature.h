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

    void link(PtrType type);
    ConstType getLinkType() const;
private:
    PtrType link_type;
};
__END_NAMESPACE__

#endif