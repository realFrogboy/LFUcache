#include "ideal_cache.h"

int idealCache(const size_t n, const size_t cacheSz, const int *arr) {
    assert(arr);

    distance<int> *dist = new distance<int>[n];
    assert(dist);

    fillDist(dist, arr, n);

    idealCache_t<int> cache(cacheSz, 0);

    int hits = 0;
    for (unsigned idx = 0; idx < n; idx++) {
        cache.decDist(dist);
        int ver = cache.insert(dist[idx]);

        if (ver)
            hits++;
    }
    delete [] dist;
    return hits;
}

template <typename KeyT = int>
int fillDist(distance<KeyT> *dist, const int *arr, const size_t n) {
    assert(dist);
    assert(arr);

    std::unordered_map<KeyT, int> hashTbl;

    for (unsigned idx = 0; idx < n; idx++) {
        dist[idx].key  = arr[idx];
        dist[idx].dist = n - idx - 1;

        auto hashElem = hashTbl.find(arr[idx]);
        if (hashElem == hashTbl.end())  // key not founded in cache
            hashTbl.insert({arr[idx], idx});
        else {                          // key founded in cache
            int prevIdx = hashElem->second;
            int distance = idx - prevIdx;
            dist[prevIdx].dist = distance;
            hashElem->second = idx;
        }
    }
    return 0;
}