#ifndef __GWI_PARSER_PARTS_BLOCK__LOGIC_STATEMENT_H__
#define __GWI_PARSER_PARTS_BLOCK__LOGIC_STATEMENT_H__

#include "../../Type/DefualtTypes.h"
#include "../../Variable/Variable.h"

#include "BinaryOperator.h"
#include "UnaryOperator.h"

namespace GWI {
    class Logic {
    protected:
        static bool checkBoolean(const Variable &var);
        static bool checkBoolean(std::initializer_list<const Variable*> vars);
    };

    class OperatorAnd : public BinaryOperator, private Logic {
        virtual inline void execute(Variable &left, Variable &right, Variable &result);
    };

    class OperatorOr : public BinaryOperator, private Logic {
        virtual inline void execute(Variable &left, Variable &right, Variable &result);
    };

    class OperatorNot : public UnaryOperator, private Logic {
        virtual inline void execute(Variable &val, Variable &result);
    };
}
#endif