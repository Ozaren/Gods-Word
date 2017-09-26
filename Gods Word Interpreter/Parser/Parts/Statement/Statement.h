#ifndef __GWI_PARSER_PARTS_BLOCK__STATEMENT_H__
#define __GWI_PARSER_PARTS_BLOCK__STATEMENT_H__

#include <vector>
#include <memory>

#include "../Variable/Variable.h"

namespace GWI {
    /*
        Represents a statement, such as add a to b and store in c
    */
    class Statement {
    public:
        virtual void execute(std::vector<VariableP> &variables) = 0;
    };

    typedef std::shared_ptr<Statement> StatementP;
}

#endif