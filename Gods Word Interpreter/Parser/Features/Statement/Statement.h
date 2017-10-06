#ifndef __GWI_PARSER_FEATURES_STATEMENT__STATEMENT_H_
#define __GWI_PARSER_FEATURES_STATEMENT__STATEMENT_H_

#include "../Pointers.h"

__START_NAMESPACE__
class Statement {
public:
    virtual void execute(ColPtrVariable vars) = 0;
};
__END_NAMESPACE__

#endif // !__GWI_PARSER_FEATURES_STATEMENT__STATEMENT_H_
