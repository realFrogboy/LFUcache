#include "lfu_cache.h"
#include "ideal_cache.h"
#include "common.h"

int main() {
    size_t n = 0, cacheSz = 0;
    std::vector<int> arr = common::getData(n, cacheSz);

    int lfuRes   = lfu_cache::lfuCache(n ,cacheSz, arr);
    int idealRes = ideal_cache::idealCache(n, cacheSz, arr);

    double lfuPercent   = (double)lfuRes/n;
    double idealPercent = (double)idealRes/n;

    std::cout << "LFU = " << lfuPercent << "; IDEAL = " << idealPercent << '\n';
    return 0;
}