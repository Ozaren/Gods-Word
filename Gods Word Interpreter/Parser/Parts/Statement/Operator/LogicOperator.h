#ifndef __GWI_PARSER_PARTS_BLOCK__LOGIC_STATEMENT_H__
#define __GWI_PARSER_PARTS_BLOCK__LOGIC_STATEMENT_H__

#include "../../Type/DefualtTypes.h"

#include "BinaryOperator.h"
#include "UnaryOperator.h"

namespace GWI {
    class Logic {
    protected:
        static bool checkBoolean(const Variable::pointer &var);
        static bool checkBoolean(std::initializer_list<const Variable::pointer*> vars);
    };

    class OperatorAnd : public BinaryOperator, private Logic {
        virtual inline void execute(Variable::pointer &left, Variable::pointer &right, Variable::pointer &result);
    };

    class OperatorOr : public BinaryOperator, private Logic {
        virtual inline void execute(Variable::pointer &left, Variable::pointer &right, Variable::pointer &result);
    };

    class OperatorNot : public UnaryOperator, private Logic {
        virtual inline void execute(Variable::pointer &val, Variable::pointer &result);
    };
}
#endif