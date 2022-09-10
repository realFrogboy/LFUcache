#include "common.h"

std::vector<int> getData(size_t &n, size_t &cacheSz) {
    int tmp = scanf("%lu %lu", &cacheSz, &n);
    assert(tmp == 2);

    std::vector<int> arr(n);

    std::for_each(arr.begin(), arr.end(), [](int& curr) {
        std::cin >> curr;
        assert(std::cin.good());
    });
    return arr;
}