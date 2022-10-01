#pragma once

#include <iostream>
#include <assert.h>

namespace costom_type{

class page_t {
    public:

    int idx;
    char data[600] {};

    page_t(const int id) : idx(id) {};

    int getKey() const { return idx; }

    inline void slowGet(const int key);
};

inline void page_t::slowGet(const int key) {
    for(int idx = 0; idx < 600; idx++)
        data[idx] = 'A';
    int tmp = key; 
    tmp++;
}

} // costom_type