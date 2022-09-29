#include "ideal_cache.h"

namespace ideal_cache {

int idealCache(const size_t n, const size_t cacheSz, const std::vector<int>& arr) {
    std::vector<distance<int>> dist(n);

    fillDist(dist, arr, n);

    idealCache_t<int> cache(cacheSz, 0);

    int hits = 0;
    for (unsigned idx = 0; idx < n; idx++) {
        int ver = cache.insert(dist[idx]);

        if (ver)
            hits++;
    }
    return hits;
}

template <typename KeyT = int>
int fillDist(std::vector<distance<KeyT>>& dist, const std::vector<int>& arr, const size_t n) {
    std::unordered_map<KeyT, int> hashTbl;

    for (unsigned idx = 0; idx < n; idx++) {
        dist[idx].key  = arr[idx];
        dist[idx].dist = INT_MAX;

        auto hashElem = hashTbl.find(arr[idx]);
        if (hashElem == hashTbl.end())  // key not founded in cache
            hashTbl.insert({arr[idx], idx});
        else {                          // key founded in cache
            int prevIdx = hashElem->second;
            dist[prevIdx].dist = idx;
            hashElem->second = idx;
        }
    }
    return 0;
}

} // ideal_cache