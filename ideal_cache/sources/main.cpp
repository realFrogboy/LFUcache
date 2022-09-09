#include "ideal_cache.h"

int main() {
    size_t n = 0, cacheSz = 0;

    int tmp = scanf("%lu %lu", &n, &cacheSz);
    assert(tmp == 2);

    int *arr = new int[n];
    assert(arr);

    for (unsigned idx = 0; idx < n; idx++) {
        tmp = scanf("%d", &arr[idx]);
        assert(tmp == 1);
    }

    int res = idealCache(n, cacheSz, arr);

    printf("%d\n", res);

    delete [] arr;
    return 0;
}