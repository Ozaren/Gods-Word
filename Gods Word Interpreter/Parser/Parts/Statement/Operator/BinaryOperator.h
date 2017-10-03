#ifndef __GWI_PARSER_PARTS_BLOCK__BINARY_OPERATOR_H__
#define __GWI_PARSER_PARTS_BLOCK__BINARY_OPERATOR_H__

#include <vector>

#include "../Statement.h"
#include "../../Variable/Variable.h"

namespace GWI {
    class BinaryOperator : public Statement {
    public:
        virtual void execute(std::vector<Variable::pointer> &variables) final;

        virtual inline void execute(Variable::pointer &left, Variable::pointer &right, Variable::pointer &result) = 0;
    };
}
#endif