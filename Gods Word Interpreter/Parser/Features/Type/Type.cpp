#include "Type.h"

using namespace std;
using namespace GWI;

Type::Type(string _name, string _group, ColType &_dynamic_value_types, ColValue &_static_values, size_t _known_size)
    : name(_name), group(_group), known_size(_known_size),
    static_values(_static_values), dynamic_value_types(_dynamic_value_types) {

}

size_t Type::getObjectSize() const {
    if (known_size <= 0) {
        size_t size = 0;

        for (PtrType t : dynamic_value_types) {
            size += t->getObjectSize();
        }

        return size;
    }
    else {
        return known_size;
    }
}

ColValue& Type::getStaticValues() {
    return static_values;
}

const ColType& Type::getDynamicValueTypes() const {
    return dynamic_value_types;
}
