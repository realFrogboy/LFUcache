#include "lfu_cache.h"
#include "ideal_cache.h"
#include "common.h"

int main() {
    size_t n = 0, cacheSz = 0;
    int *arr = getData(n, cacheSz);

    int lfuRes   = lfuCache(n ,cacheSz, arr);
    int idealRes = idealCache(n, cacheSz, arr);

    double lfuPercent   = (double)lfuRes/n;
    double idealPercent = (double)idealRes/n;

    printf("LFU = %.2lf%%; IDEAL = %.2lf%%\n", lfuPercent, idealPercent);

    delete [] arr;
    return 0;
}