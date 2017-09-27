#ifndef __GWI_PARSER_PARTS_TYPE__FUNCTION_BODY_H__
#define __GWI_PARSER_PARTS_TYPE__FUNCTION_BODY_H__

#include <vector>

#include "../Statement/Block/Block.h"

namespace GWI {
    class FunctionBody : public Block {
    public:
        FunctionBody(std::vector<StatementP> &statements);
    };
    typedef std::shared_ptr<FunctionBody> FunctionBodyP;
}

#endif