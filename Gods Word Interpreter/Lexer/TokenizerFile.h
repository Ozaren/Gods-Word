#ifndef __GWI_LEXER__TOKENIZER_FILE_H__
#define __GWI_LEXER__TOKENIZER_FILE_H__

#include <fstream>

#include "Tokenizer.h"

class TokenizerFile : public Tokenizer {
public:
    TokenizerFile(const char* file);

    virtual bool isDone();

private:
    std::ifstream input;

protected:
    virtual char peek();
    virtual char vnextChar();
    virtual void vmoveBack();
};

#endif // !__GWI_LEXER__TOKENIZER_FILE_H__