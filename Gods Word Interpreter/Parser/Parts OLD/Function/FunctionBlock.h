#ifndef __GWI_PARSER_PARTS_FUNCTION__FUNCTION_BLOCK_H__
#define __GWI_PARSER_PARTS_FUNCTION__FUNCTION_BLOCK_H__

#include <vector>

#include "../Variables/Variable.h"
#include "../Block/Block.h"

class FunctionBlock : public Block {
    friend class Function;

public:
    FunctionBlock();

    virtual void execute(std::vector<Variable> variables);

private:
    std::vector<Block*> statements;
};

#endif