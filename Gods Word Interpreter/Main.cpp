#include <iostream>
#include <vector>

#include <boost/any.hpp>

#include "Lexer/Token.h"
#include "Lexer/Keywords.h"
#include "Lexer/Tokenizer.h"
#include "Lexer/TokenizerFile.h"

#include "Parser/Features/Pointers.h"

#include "Parser/Features/Type/DefualtType.h"
#include "Parser/Features/Type/Type.h"
#include "Parser/Features/Type/TypeSignature.h"

#include "Parser/Features/Variable/Variable.h"

using namespace std;
__USE_NAMESPACE__

int main() {
    try {
        cout << def_type::BOOL->signature->full_name << endl;

        PtrTypeSignature sig(new TypeSignature("big", "user def"));

        ColPtrVariable cpv = ColPtrVariable();
        ColConstTypeSignature ccts = ColConstTypeSignature({  });

        PtrType type(new Type(sig, cpv, ccts));

        cout << type->signature->name << endl;
        cout << sig->bound_to()->signature->name << endl;
        // cout << var->get<PtrVariable>(0)->type->signature->name << endl;
    }
    catch (const char *c) {

    }
    catch (...) {

    }
    system("pause");
    return 0;
}

#if false
long GetFileSize(std::string filename)
{
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

#include <sys\timeb.h>
int main1() {
    cout << "start" << endl;

    struct timeb start, end;
    int diff;
    int i = 0;
    ftime(&start);

    //TokenizerFile t("00 Examples/commments and output.gw");
    const char* filename = "00 Examples/load_test.gw";
    TokenizerFile t(filename);
    vector<Token> tokens;

    while (!t.isDone()) {
        Token tok(t.next());
        tokens.push_back(tok);
        // string val(tok.getValue());

        // cout << tok.getType() << '\t' << (val == "\n" ? "$NEWLINE$" : val) << endl;
    }

    ftime(&end);
    diff = (int)(1000.0 * (end.time - start.time)
        + (end.millitm - start.millitm));

    printf("\Lexing took %u milliseconds\n", diff);
    printf("Speed: %u bytes/sec\n", GetFileSize(filename) * 1000 / diff);
    printf("Vector size: %u\n", tokens.capacity() * sizeof(Token) + sizeof(tokens));

    system("pause");

    return 0;
}
#endif