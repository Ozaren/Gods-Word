#ifndef __GWI_PARSER__PARSER_H__
#define __GWI_PARSER__PARSER_H__

#include <vector>

#include "../Lexer/Tokenizer.h"

class Parser {
public:
    Parser(Tokenizer &tokenizer);

    void parse();

private:
    Tokenizer &tokenizer;
    std::vector<Token> tokens;
};


#endif
