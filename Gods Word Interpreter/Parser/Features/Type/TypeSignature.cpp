#include "TypeSignature.h"

#include "Type.h"

#include "../Error/error_handling.h"

using namespace std;
__USE_NAMESPACE__

TypeSignature::TypeSignature(std::string _name, std::string _group)
    : name(_name), group(_group), link_type(nullptr) {
}

void TypeSignature::link(PtrType type) {
    if (link_type.get() == (Type*) nullptr)
        link_type = type;
    else
        PRINT_ERROR("Type Signature Link Error", "Cannot re-link a type signature");
}

ConstType TypeSignature::getLinkType() const {
    return link_type;
}