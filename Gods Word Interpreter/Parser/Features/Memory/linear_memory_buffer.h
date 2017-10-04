#pragma once

#include <vector>
#include <iostream>

#include "../Error/error_handling.h"
#include "memory_buffer.h"

struct linear_memory_buffer : public memory_buffer {
    linear_memory_buffer(size_t size = 0) : memory_buffer(size), pos(0) {}


    template<typename type>
    void add_val(type t) {
        add_help_pre(t);

        add_help_post<type>(memory_buffer::set<type>(pos, t), false);
    }

    /**
    Adds type t to first empty spot with space, if not enough space,
    automatically calls memory::expand
    */
    template<typename type>
    void add(type &t) {
        add_help_pre(t);

        add_help_post<type>(memory_buffer::set<type>(pos, t), false);
    }

    /**
    Adds type *t to first empty spot with space, if not enough space,
    automatically calls memory_buffer::expand
    if passing a anonomous object, please mark manage as true or you will leak memory
    manage allows this object to manage a pointer, and will put it into a std::shared_ptr
    for deallocation information, see std::shared_ptr
    */
    template<typename type>
    void addp(type *t, bool manage = false) {
        add_help_pre(t);

        add_help_post<type*>(memory_buffer::setp<type>(pos, t, manage), true);
    }

    /**
    Gets a value from memory and casts to type
    */
    template<typename type = char>
    type get_item(size_t position) {
        return get_item_help<type>(position, false);
    }

    /**
    Gets a pointer from memory and casts to type*,
    */
    template<typename type = char>
    type* getp_item(size_t position) {
        return get_item_help<type*>(position, true);
    }

    template<typename type = char>
    int set(size_t address, type& val) = delete;

    template<typename type = char>
    int setp(size_t address, type* val, bool manage) = delete;

    virtual size_t size() const { return pos; }

    friend std::ostream& operator<<(std::ostream& os, const linear_memory_buffer *m) {
        return (os << (memory_buffer*)m);
    }

private:
    size_t pos;
    std::vector<size_t> positions;
    std::vector<size_t> types;
    std::vector<bool> is_pointer;

    template<typename type>
    void add_help_pre(type &t) {
        while (!canset<type>(pos, t)) {
            expand();
        }
    }

    template<typename type>
    void add_help_post(size_t size, bool pointer) {
        positions.push_back(pos);
        pos += size;
        types.push_back(typeid(type).hash_code());
        is_pointer.push_back(pointer);
    }

    /**
    Gets a value from memory and casts to type
    */
    template<typename type = char>
    type get_item_help(size_t position, bool is_point) {
        if (position >= positions.size()) {
            PRINT_ERROR("Bad Address", "address is out of range");
        }

        if (is_pointer[position] != is_point) {
            if (is_point) {
                PRINT_ERROR("Bad Type", "cannot use getp_item to get a non-pointer");
            }
            else {
                PRINT_ERROR("Bad Type", "cannot use get_item to get a pointer");
            }
        }

        if (types[position] != typeid(type).hash_code()) {
            PRINT_ERROR("Bad Type", "incorrect type");
        }

        return get<type>(positions[position]);
    }
};
