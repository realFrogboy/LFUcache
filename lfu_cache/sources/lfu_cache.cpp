#include "lfu_cache.h"

namespace lfu_cache {

int lfuCache(const size_t n, const size_t cacheSz, const std::vector<int>& arr) {
    cache_t<int> cache(cacheSz, 0);

    int hits = 0;
    for (unsigned idx = 0; idx < n; idx++) {
        int req = arr[idx];

        int ver = cache.insert(req);

        if (ver) {
            cache.access(req);
            hits++;
        }
    }
    return hits;
}

} // lfu_cache