#ifndef __GWI_PARSER_PARTS_BLOCK__STATEMENT_H__
#define __GWI_PARSER_PARTS_BLOCK__STATEMENT_H__

#include <memory>
#include <vector>

#include "../Variable/Variable.h"

namespace GWI {
    /*
        Represents a statement, such as add a to b and store in c
    */
    class Statement {
    public:
        typedef std::shared_ptr<Statement> pointer;

        virtual void execute(std::vector<Variable::pointer> &variables) = 0;
    };
}

#endif