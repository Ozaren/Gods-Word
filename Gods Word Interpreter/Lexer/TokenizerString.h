#ifndef __GWI_LEXER__TOKENIZER_STRING_H__
#define __GWI_LEXER__TOKENIZER_STRING_H__

#include <string>

#include "Tokenizer.h"

class TokenizerString : public Tokenizer {
public:
    TokenizerString(std::string input);
    TokenizerString(std::string input, int length);

    virtual bool isDone();

private:
    std::string input;
    int length, current;

protected:
    virtual char peek();
    virtual char vnextChar();
    virtual void vmoveBack();
};

#endif // !__GWI_LEXER__TOKENIZER_STRING_H__