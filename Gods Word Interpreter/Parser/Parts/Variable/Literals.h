#ifndef __GWI_PARSER_PARTS_VARIABLE__VARIABLE_H__
#define __GWI_PARSER_PARTS_VARIABLE__VARIABLE_H__

#include <string>

#include "../Type/Type.h"
#include "../Type/DefualtTypes.h"

namespace GWI {
    namespace literal_value {
        template<typename val_type>
        class Literal {
        public:
            Literal(const Type::pointer &_type, val_type _value) : type(_type), value(_value) { }

            const Type::pointer type;
            const val_type value;

            const val_type getValue() const { return value; }
        };

        class Boolean : public Literal<bool> {
        public:
            Boolean(bool value = false);
        };

        class Integer : public Literal<int> {
        public:
            Integer(int value = 0);
        };

        class U_Integer : public Literal<unsigned int> {
        public:
            U_Integer(unsigned int value = 0);
        };

        class Float : public Literal<double> {
        public:
            Float(double value = 0);
        };

        class Character : public Literal<char> {
        public:
            Character(char value = 0);
        };

        class String : public Literal<std::string> {
        public:
            String(std::string value = "");
        };
    }
}

#endif
