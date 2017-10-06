#include "error_handling.h"



#ifdef _WIN32
void printStackTrace(std::ostream& out)
{
    const int kMaxCallers = 62;

    void *callers_stack[kMaxCallers];
    HANDLE process = GetCurrentProcess();

    SymSetOptions(0x00000010); // same as SymSetOptions(SYMOPT_LOAD_LINES);
    SymInitialize(process, NULL, TRUE);
    unsigned short frames = CaptureStackBackTrace(1, kMaxCallers, callers_stack, NULL);

    SYMBOL_INFO  *symbol = (SYMBOL_INFO *)calloc(sizeof(SYMBOL_INFO) + 256 * sizeof(char), 1);
    symbol->MaxNameLen = 255;
    symbol->SizeOfStruct = sizeof(SYMBOL_INFO);

    PIMAGEHLP_LINE line_value = (PIMAGEHLP_LINE)calloc(sizeof(_IMAGEHLP_LINE), 1);
    line_value->SizeOfStruct = sizeof(line_value);
    DWORD dwDisplacement;

    const unsigned short  MAX_CALLERS_SHOWN = 6;
    for (unsigned int i = 0; i < frames; i++)
    {
        SymGetLineFromAddr(process, (DWORD64)(callers_stack[i]), &dwDisplacement, line_value);
        SymFromAddr(process, (DWORD64)(callers_stack[i]), 0, symbol);
        //out << "*** " << i << ": " << callers_stack[i] << " " << symbol->Name << " - 0x" << symbol->Address << std::endl;
        out << '\t' << line_value->FileName << "::" << line_value->LineNumber << "\t" << symbol->Name << std::endl;

        if (std::string(symbol->Name) == "main")
            break;
    }

    free(symbol);
    free(line_value);
}

#endif
