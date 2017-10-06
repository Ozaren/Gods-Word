#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <sstream>

#include "../Error/error_handling.h"

struct memory_buffer {
    std::vector<char> buffer;

    memory_buffer(size_t size = 0) : buffer(size) {}
    virtual ~memory_buffer() { }

    /**
    Gets a value from memory and casts to type
    */
    template<typename type = char>
    type get(size_t address) { return *getLoc<type>(address); }

    /**
    Gets a pointer from memory and casts to type*
    */
    template<typename type = char>
    type* getp(size_t address) { return get<type*>(address); }

    /**
    Puts a value in memory
    */
    template<typename type = char>
    int canset(size_t address, type& val) {
        int size = sizeof(val);
        return size + address <= buffer.size();
    }
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

            PRINT_ERROR("Bad Store Error", ss.str());
        }

        *getLoc<type>(address) = val;
        return size;
    }

    /**
    Puts a pointer in memory with a flag on
    whether this construct should manage the pointer
    if passing a anonomous object, please mark manage as true or you will leak memory
    manage allows this object to manage a pointer, and will put it into a std::shared_ptr
    for deallocation information, see std::shared_ptr
    */
    template<typename type = char>
    int setp(size_t address, type* val, bool manage = false) {
        set<type*>(address, val);
        if (manage)
            pointers.push_back(std::shared_ptr<type>(val));
        return sizeof(val);
    }

    /**
    doubles buffer size, if buffer is zero size, make 16 bytes
    */
    void expand() {
        if (buffer.size() == 0)
            expand(0x10);
        else
            expand(buffer.size());
    }

    /**
    expand buffer size by delta
    */
    void expand(size_t delta) {
        buffer.resize(buffer.size() + delta);
    }

    virtual size_t size() const { return buffer.size(); }

    friend std::ostream& operator<<(std::ostream& os, const memory_buffer *m) {
        for (size_t i = 0; i < m->buffer.size(); i++) {
            char c = m->buffer[i];
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

    void tighten() {
        int size = this->size();
        int buf_size = buffer.size();
        if (size < 0) {
            PRINT_ERROR("Tighten Failed", "invalid size (negative size)");
        }
        else if (size < buf_size) {
            buffer.resize(size);
            std::vector<char>(buffer).swap(buffer);
        }
        else if (size > buf_size) {
            PRINT_ERROR("Tighten Failed", "invalid size (size larger than buffer size)");
        }
    }

    size_t memory_used() {
        return buffer.capacity() + sizeof(*this);
    }
private:
    std::vector<std::shared_ptr<void>> pointers;

    template<typename type>
    type* getLoc(int address) { return ((type*)&buffer[address]); }
};
