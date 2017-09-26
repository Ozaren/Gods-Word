#ifndef __GWI_PARSER_PARTS_VARIABLE__VARIABLE_H__
#define __GWI_PARSER_PARTS_VARIABLE__VARIABLE_H__

#include "../Type/Type.h"

namespace GWI {
    class Variable {
    public:
        Variable(const TypeP &type, void *value);

        const TypeP type;
        void *value;

        bool operator==(const Variable &v) const { return *v.type == *type && v.value == value; }
        bool operator!=(const Variable &v) const { return !operator==(v); }
    };

    typedef std::shared_ptr<Variable> VariableP;
}
#endif