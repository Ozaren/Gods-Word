#ifndef __GWI_PARSER_PARTS_BLOCK__BLOCK_H__
#define __GWI_PARSER_PARTS_BLOCK__BLOCK_H__

#include <vector>

#include "../Variables/Variable.h"

struct Block {
    virtual void execute(std::vector<Variable> variables) = 0;
};

#endif
