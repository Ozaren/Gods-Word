#ifndef __GWI_PARSER_PARTS_TYPE__FUNCTION_BODY_H__
#define __GWI_PARSER_PARTS_TYPE__FUNCTION_BODY_H__

// #include <memory>
#include <vector>

#include "../Statement/Statement.h"
#include "../Statement/Block/Block.h"

namespace GWI {
    class FunctionBody : public Block {
    public:
        // typedef std::shared_ptr<FunctionBody> pointer;

        FunctionBody(std::vector<Statement> &statements);
    };
}

#endif