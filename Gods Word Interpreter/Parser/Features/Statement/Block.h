#ifndef __GWI_PARSER_FEATURES_STATEMENT__BLOCK_H_
#define __GWI_PARSER_FEATURES_STATEMENT__BLOCK_H_

#include "../Pointers.h"

#include "Statement.h"

namespace GWI {
    class Block : Statement {
    public:
        virtual void execute(ColValue &vars) final;

    public:
        ColStatement statements;
        ColValue variables;
    };
}

#endif // !__GWI_PARSER_FEATURES_STATEMENT__BLOCK_H_
