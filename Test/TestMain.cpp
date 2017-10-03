#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "linear_memory_buffer.h"

using namespace std;

class A {
public:
    vector<unsigned char> hell;

    A() {
        for (unsigned char i = 0; i < 256; i++) {
            hell.push_back(i);
            if (i == 255)
                break;
        }
    }

    ~A() {
        cout << "delete A" << endl;
    }
};

int main() {
    cout << boolalpha;

    try {
        linear_memory_buffer mem;
        for(size_t i = 0; i < 16; i++)
            mem.addp(new A(), true);
    }
    catch (const char *c) {

    }

    system("pause");
}
