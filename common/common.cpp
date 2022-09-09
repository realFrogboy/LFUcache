#include "common.h"

int *getData(size_t &n, size_t &cacheSz) {
    int tmp = scanf("%lu %lu", &n, &cacheSz);
    assert(tmp == 2);

    int *arr = new int[n];
    assert(arr);

    for (unsigned idx = 0; idx < n; idx++) {
        tmp = scanf("%d", &arr[idx]);
        assert(tmp == 1);
    }
    return arr;
}