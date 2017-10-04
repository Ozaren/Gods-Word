#ifndef __GWI_PARSER_FEATURES_STATEMENT__STATEMENT_H_
#define __GWI_PARSER_FEATURES_STATEMENT__STATEMENT_H_

#include "../Pointers.h"

namespace GWI {
    class Statement {
    public:
        virtual void execute(ColValue vars) = 0;
    };
}

#endif // !__GWI_PARSER_FEATURES_STATEMENT__STATEMENT_H_
