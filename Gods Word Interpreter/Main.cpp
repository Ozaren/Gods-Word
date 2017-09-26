#include <iostream>
#include <vector>

#include "Lexer/Token.h"
#include "Lexer/Keywords.h"
#include "Lexer/Tokenizer.h"
#include "Lexer/TokenizerFile.h"

/*
#include "Parser/Parts/Type/Type.h"
#include "Parser/Parts/Type/DefualtTypes.h"
#include "Parser/Parts/Variables/Literals.h"
#include "Parser/Parts/Variables/Variable.h"
*/

using namespace std;

int main() {

}

int main1() {
    cout << "start" << endl;

    TokenizerFile t("00 Examples/commments and output.gw");
    vector<Token> tokens;

    while (!t.isDone()) {
        Token tok(t.next());
        string val(tok.getValue());

        cout << tok.getType() << '\t' << (val == "\n" ? "$NEWLINE$" : val) << endl;
    }

    system("pause");

    return 0;
}