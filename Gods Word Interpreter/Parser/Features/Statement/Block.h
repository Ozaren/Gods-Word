#ifndef __GWI_PARSER_FEATURES_STATEMENT__BLOCK_H_
#define __GWI_PARSER_FEATURES_STATEMENT__BLOCK_H_

#include "../Pointers.h"

#include "Statement.h"

__START_NAMESPACE__

class Block : Statement {
public:
    virtual void execute(ColPtrVariable vars);
protected:
    ColPtrTypeSignature var_types;
};

__END_NAMESPACE__

#endif // !__GWI_PARSER_FEATURES_STATEMENT__STATEMENT_H_
