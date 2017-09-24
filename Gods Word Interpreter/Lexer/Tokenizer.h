#ifndef __GWI_LEXER__TOKENIZER_H__
#define __GWI_LEXER__TOKENIZER_H__

#include <string>
#include <stack>

#include "Token.h"

class Tokenizer {
public:
    Tokenizer();
    virtual ~Tokenizer();

    virtual Token next();
    virtual Token last() const;

    virtual bool isDone() = 0;

protected:
    virtual char peek() = 0;
    virtual char vnextChar() = 0;
    virtual void vmoveBack() = 0;

private:
    int current;
    int quotes;

    std::stack<int> markers;
    Token lastToken;

    Token nextToken();

    void skipWhiteSpace();
    std::string nextWord();

    void setMarker();
    void popMarker();

    char nextChar();
    void moveBack();
};

#endif // !__GWI_LEXER__TOKENIZER_H__