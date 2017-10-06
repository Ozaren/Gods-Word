#pragma once

#include <iostream>
#include <string>
#include <Windows.h>

#include "DbgHelp.h"
#pragma comment(lib, "Dbghelp.lib")

#ifndef _WIN32
#define PRINT_ERROR(title,msg)
#else
void printStackTrace(std::ostream& out);

#define PRINT_ERROR(title,msg) std::cout << title << ": " << msg << std::endl; printStackTrace(std::cout); throw ""


#endif
