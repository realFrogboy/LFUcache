#pragma once

#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iostream>

namespace common {

template <typename KeyT>
std::vector<KeyT> getData(size_t &n, size_t &cacheSz) {
    std::cin >> cacheSz >> n;
    assert(std::cin.good());

    std::vector<KeyT> arr(n);

    std::for_each(arr.begin(), arr.end(), [](KeyT& curr) {
        std::cin >> curr;
        assert(std::cin.good());
    });
    return arr;
}

} // common