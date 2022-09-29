#include "common.h"
#include "ideal_cache.h"

int main() {
    size_t n = 0, cacheSz = 0;
    std::vector<int> arr = common::getData(n, cacheSz);

    int res = ideal_cache::idealCache(n, cacheSz, arr);

    std::cout << res << '\n';
    return 0;
}