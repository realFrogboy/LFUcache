#include "common.h"

namespace common {

std::vector<int> getData(size_t &n, size_t &cacheSz) {
    std::cin >> cacheSz >> n;
    assert(std::cin.good());

    std::vector<int> arr(n);

    std::for_each(arr.begin(), arr.end(), [](int& curr) {
        std::cin >> curr;
        assert(std::cin.good());
    });
    return arr;
}

} // common