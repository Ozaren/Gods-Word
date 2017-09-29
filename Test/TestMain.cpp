#include <vector>
#include <iostream>
#include <typeinfo>
#include <sstream>
#include <string>
#include <array>

using namespace std;

class Error {
public:
    const string name;
    const string message;
    Error(string name, string s) : name(name), message(s) {}

    friend ostream& operator<<(ostream& os, const Error &e) {
        os << e.name << ": " << e.message;
        return os;
    }
};

struct memory {
    vector<char> buffer;

    memory(size_t size = 0) : buffer(size) {}
    virtual ~memory() {
        for (size_t i = 0; i < pointers.size(); i++)
            delete pointers[i];
    }

    /**
    Gets a value from memory and casts to type
    */
    template<typename type = char>
    type get(size_t address) { return *getLoc<type>(address); }

    /**
    Gets a pointer from memory and casts to type*
    */
    template<typename type = char>
    type* getp(size_t address) { return *getLoc<type*>(address); }

    /**
    Puts a value in memory
    */
    template<typename type = char>
    int set(size_t address, type& val) {
        int size = sizeof(val);
        if (size + address > buffer.size()) {
            std::stringstream ss;
            ss << "Could not store at " << address;
            ss << ", needs " << size << " bytes";
            ss << ", only " << (buffer.size() - address) << " bytes";
            ss << " remaining";

            throw Error("Bad Store Error", ss.str());
        }

        *getLoc<type>(address) = val;
        return size;
    }

    /**
    Puts a pointer in memory with a flag on
    whether this construct should manage the pointer
    */
    template<typename type = char>
    int setp(size_t address, type* val, bool manage = false) {
        set<type*>(address, val);
        if (manage)
            pointers.push_back((void*)val);
        return sizeof(val);
    }

    /**
    doubles buffer size
    */
    void expand() {
        expand(buffer.size());
    }

    /**
    expand buffer size by delta
    */
    void expand(size_t delta) {
        buffer.resize(buffer.size() + delta);
    }

    /**
    Overload to print all buffer contents
    */
    friend ostream& operator<<(ostream& os, const memory &m) {
        for (size_t i = 0; i < m.buffer.size(); i++) {
            char c = m.buffer[i];
            if (i > 0) {
                os << ' ';

                if (i % 16 == 0) {
                    os << '\n';
                }
                else if (i % 8 == 0) {
                    os << ' ';
                }
            }

            int hex = (int)c;
            os << std::hex;
            os << ((hex & 0xF0) >> 4) << (hex & 0x0F);
        }
        os << std::dec;

        return os;
    }
private:
    vector<void*> pointers;

    template<typename type>
    type* getLoc(int address) { return ((type*)&buffer[address]); }
};

struct managed_memory : protected memory {
    size_t pos;
    vector<size_t> sizes;

    managed_memory(size_t size = 0) : memory(size), pos(0) {}

    template<typename type>
    void add(type t) {
        size_t size = set<type>(pos, t);
        pos += size;
        sizes.push_back(size);
    }

    friend ostream& operator<<(ostream& os, const managed_memory &m) {
        os << ((memory)m);

        return os;
    }
};

int main() {
    cout << boolalpha;
    bool caught = false;
    try {
        constexpr int count = 8;
        managed_memory m(count * sizeof(double));

        for (int i = 0; i < count; i++) {
            m.add<double>(i);
        }

        cout << m << endl;
    }
    catch (const Error &e) {
        cout << e << endl;
    }

    system("pause");
}
