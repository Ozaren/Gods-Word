#include <iostream>

#include "Tokenizer.h"
#include "Keywords.h"

using namespace std;

#define END_CHECK if(isDone() || peek() == -1) return key::END

bool isWhiteSpace(char x) {
    return (x == ' ' || x == '\t');
}

bool isnum(char x) {
    return x >= '0' && x <= '9';
}

Tokenizer::Tokenizer() {

}

Tokenizer::~Tokenizer() {

}

Token Tokenizer::next() {
    Token tok;

    do {
        tok = nextToken();
    } while (lastToken == key::NEW_LINE && tok == key::NEW_LINE); // remove redundant newlines

    return (lastToken = tok);
}

Token Tokenizer::last() const {
    return lastToken;
}

void Tokenizer::setMarker() {
    markers.push(current);
}

void Tokenizer::popMarker() {
    if (!markers.empty()) {
        int mark = markers.top();
        markers.pop();
        while (mark < current)
            moveBack();
    }
}

char Tokenizer::nextChar() {
    current++;
    return vnextChar();
}

void Tokenizer::moveBack() {
    current--;
    return vmoveBack();
}

void Tokenizer::skipWhiteSpace() {
    if (quotes == 1)
        return;
    while (isWhiteSpace(nextChar())) {

    }

    moveBack();
}

string Tokenizer::nextWord() {
    char c;
    string str;

    while (!isDone() && !isWhiteSpace((c = nextChar())) && !key::isPunctuation(c)) {
        str += c; // build the first arg
    }

    return str;
}

Token Tokenizer::nextToken() {
    // check for end of file
    END_CHECK;

    char c;

    skipWhiteSpace();
    c = nextChar();

    // Handle Comments
    if (c == '#') { // if block comment, go to ending tag, or end of file, whichever comes first
        END_CHECK;
        c = nextChar();

        if (c == '#') {
            while (true) {
                END_CHECK;

                c = nextChar();
                if (c != '#')
                    continue;

                END_CHECK;

                c = nextChar();

                if (c == '#') {
                    break;
                }
            }
            c = nextChar(); // Discard last comment symbol
        }
        else {
            // If line comment go to end of line 
            // or end of file, whichever comes first
            while (!isDone() && (c = nextChar()) != '\n' && c != EOF) {

            }
            END_CHECK;
        }
    }

    setMarker();
    for (Token t : key::getOperators()) {
        string val(t.getValue());
        if (val[0] == c) {
            setMarker();

            bool isSame = true;

            for (size_t i = 1; i < val.length(); i++) {
                if (val[i] != nextChar()) {
                    isSame = false;
                    break;
                }
            }

            popMarker();
            if (isSame)
                return t;
        }
    }
    popMarker();

    switch (c) {
    case '"': {
        char s = nextChar();
        string str;

        while (!isDone() && s != '"') {
            str += s;
            s = nextChar();
        }

        return Token(TokenType::LITERAL_STRING, str);
    }
    case '\n':
        return key::NEW_LINE;
    case '{':
        return key::BLOCK_OPEN;
    case '}':
        return key::BLOCK_CLOSE;
    case '(':
        return key::PAREN_OPEN;
    case ')':
        return key::PAREN_CLOSE;
    case '[':
        return key::BRACK_OPEN;
    case ']':
        return key::BRACK_CLOSE;
    case '@': {
        return Token(TokenType::COMPILER_NOTE, nextWord());
    }
    default:
        break;
    }

    // Handle literal numbers
    if (isnum(c) || c == '.') {
        string num;

        bool f_point = (c == '.'), f_radix_settable = (c == '0'), f_bin = false, f_hex = false, f_oct = false, f_end = false;

        do {
            if (c == '.')
                if (f_point)
                    f_end = true;
                else
                    f_point = true;
            if (c == 'h' || c == 'o' || c == 'b') {
                if (!f_radix_settable)
                    f_end = true;
                else
                    f_radix_settable = false;

                if (c == 'h') {
                    f_hex = true;
                }
                if (c == 'o') {
                    f_oct = true;
                }
                if (c == 'b') {
                    f_bin = true;
                }
            }

            if (f_end || c == ' ' || c == '\n' || c == EOF) {
                cout << "#####" << c << endl;
                if (c == '\n')
                    moveBack();
                f_end = true;
                break;
            }

            num += c;

            c = nextChar();
            if (c != '.' && key::isPunctuation(c))
                f_end = true;

        } while (isnum(c) || c == 'h' || c == 'o' || c == 'b' || c == '.' || c == ' ' || c == '\n' || c == EOF);

        if (f_point) {
            moveBack();
            return Token(TokenType::LITERAL_FLOAT, num);
        }
        else {
            moveBack();
            return Token(TokenType::LITERAL_INT, num);
        }
    }
    moveBack();

    string word(nextWord());

    if (word.length() == 0)
        return key::EMPTY;

    // Check all keywords
    for (Token tok : key::getPunctuation()) {
        if (tok.getValue() == word) {
            return tok;
        }
    }

    TokenType lastType = last().getType();

    if ((lastType == TokenType::CN_ARG || lastType == TokenType::COMPILER_NOTE) && peek() != '\n') {
        return Token(TokenType::CN_ARG, word);
    }

    if (isalpha(word[0])) {
        bool isID = true;

        for (char w : word) {
            if (!isalnum(w)) {
                isID = false;
                break;
            }
        }

        if (isID) {
            moveBack();
            return Token(TokenType::IDENTIFIER, word);
        }
    }

    cout << "@@@";

    for (char c : word) {
        cout << "\t" << (int)c;
    }

    cout << endl;

    return Token(TokenType::UNKNOWN, word);
}
