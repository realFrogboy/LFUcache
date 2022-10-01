#include "common.h"
#include "ideal_cache.h"

int main() {
    size_t n = 0, cacheSz = 0;
    std::vector<int> arr = common::getData<int>(n, cacheSz);

    int res = ideal_cache::idealCache<int, costom_type::page_t>(n, cacheSz, arr);

    std::cout << res << std::endl;
    return 0;
}