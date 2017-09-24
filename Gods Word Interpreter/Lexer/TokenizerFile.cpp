#include "TokenizerFile.h"

#include <iostream>

using namespace std;

TokenizerFile::TokenizerFile(const char* file)
    : input(file) {

}

bool TokenizerFile::isDone() {
    return input.eof() || peek() == EOF;
}

char TokenizerFile::peek() {
    return input.peek();
}

char TokenizerFile::vnextChar() {
    return input.get();
}

void TokenizerFile::vmoveBack() {
    input.unget();
}