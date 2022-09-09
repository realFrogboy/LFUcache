#include "common.h"
#include "ideal_cache.h"

int main() {
    size_t n = 0, cacheSz = 0;
    int *arr = getData(n, cacheSz);

    int res = idealCache(n, cacheSz, arr);

    printf("%d\n", res);

    delete [] arr;
    return 0;
}