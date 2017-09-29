#ifndef __GWI_PARSER_PARTS_VARIABLE__VARIABLE_H__
#define __GWI_PARSER_PARTS_VARIABLE__VARIABLE_H__

#include <memory>

#include "../Type/Type.h"
#include "../Type/DefualtTypes.h"

namespace GWI {
    namespace literal_value {
        class Literal {
        public:
            Literal(const TypeP &type, void* value);

            const TypeP type;
            const void *value;

            const void* getValue() const { return value; }
        };

        class Boolean : public Literal {
        public:
            Boolean(void* value = (void*)false);
        };

        class Integer : public Literal {
        public:
            Integer(void* value = (void*)0);
        };

        class U_Integer : public Literal {
        public:
            U_Integer(void* value = (void*)0);
        };

        class Float : public Literal {
        public:
            Float(void* value = (void*)0);
        };

        class Character : public Literal {
        public:
            Character(void* value = (void*)0);
        };

        class String : public Literal {
        public:
            String(void* value = nullptr);
        };
    }
}

#endif
