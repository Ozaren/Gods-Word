#ifndef __GWI_PARSER_FEATURES_TYPE__TYPE_H_
#define __GWI_PARSER_FEATURES_TYPE__TYPE_H_

#include <string>

#include "../Pointers.h"

namespace GWI {
    class Type {
    public:
        const std::string name;
        const std::string group;

        Type(std::string _name, std::string _group, ColType &_dynamic_value_types, ColValue &_static_values = ColValue(), size_t _known_size = 0);

        size_t getObjectSize() const;

        ColValue& getStaticValues();
        const ColType& getDynamicValueTypes() const;

    private:
        ColValue static_values;
        ColType dynamic_value_types;

        size_t known_size;
    };
}

#endif