#include "TypeSignature.h"

#include "Type.h"

#include "../Error/error_handling.h"

using namespace std;
__USE_NAMESPACE__

TypeSignature::TypeSignature(std::string _name, std::string _group)
    : name(_name), group(_group), full_name(_group + "." + _name), link_type(nullptr) {

}

const Type* TypeSignature::bound_to() const {
    return link_type;
}