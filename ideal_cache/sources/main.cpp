#include "common.h"
#include "ideal_cache.h"

int main() {
    size_t n = 0, cacheSz = 0;
    std::vector<int> arr = getData(n, cacheSz);

    int res = idealCache(n, cacheSz, arr);

    printf("%d\n", res);
    return 0;
}