#ifndef __GWI_PARSER_PARTS_BLOCK__UNARY_OPERATOR_H__
#define __GWI_PARSER_PARTS_BLOCK__UNARY_OPERATOR_H__

#include <vector>

#include "../Statement.h"

namespace GWI {
    class UnaryOperator : public Statement {
    public:
        virtual void execute(std::vector<VariableP> &variables) final;

        virtual inline void execute(VariableP &val, VariableP &result) = 0;
    };
}

#endif