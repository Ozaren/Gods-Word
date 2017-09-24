#include "TokenizerString.h"

using namespace std;

TokenizerString::TokenizerString(string input)
    : TokenizerString(input, input.length()) {

}

TokenizerString::TokenizerString(string _input, int _length)
    : input(_input), length(_length), current(0) {

}

char TokenizerString::peek() {
    if (isDone())
        return EOF;
    else
        return input[current];
}

char TokenizerString::vnextChar() {
    if (isDone())
        return EOF;
    else
        return input[current++];
}

void TokenizerString::vmoveBack() {
    current--;
}

bool TokenizerString::isDone() {
    return current >= length;
}
