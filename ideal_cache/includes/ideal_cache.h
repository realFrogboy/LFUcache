#pragma once

#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <unordered_map>
#include <vector>
#include <map>
#include "costom.h"

namespace ideal_cache {

template <typename KeyT>
struct distance {
    KeyT key;
    int dist;
};

template <typename KeyT, typename D>
struct idealCache_t {
    size_t capacity;
    size_t size;
    std::multimap<int, D> cacheElems; // TODO: KeyT -> D
    using mapIt = typename std::multimap<int, D>::iterator;

    std::unordered_map<KeyT, mapIt> hashTbl;

    idealCache_t(size_t cpty, size_t sz) : capacity(cpty), size(sz) {};


    int insert(const distance<KeyT> elem) {
        auto hashElem = hashTbl.find(elem.key);
        if (hashElem != hashTbl.end()) {  //  key found
            auto tmpData = hashElem->second->second;
            cacheElems.erase(hashElem->second);
            hashTbl.erase(hashElem);
            auto iter = cacheElems.insert({elem.dist, tmpData});
            hashTbl.insert({elem.key, iter});
            return 1;
        }

// key not found
        size++;
        if (size > capacity) {
            auto maxIter = std::prev(cacheElems.end());
            auto deletedKey = maxIter->second.getKey();
            cacheElems.erase(maxIter);
            auto deletedIter = hashTbl.find(deletedKey);
            hashTbl.erase(deletedIter);
            size--;
        }
        
        costom_type::page_t page(elem.key);
        page.slowGet(elem.key);

        auto iter = cacheElems.insert({elem.dist, page});
        hashTbl.insert({elem.key, iter});
        return 0;
    }
};


template <typename KeyT>
int fillDist(std::vector<distance<KeyT>>& dist, const std::vector<KeyT>& arr, const size_t n) {
    std::unordered_map<KeyT, int> hashTbl;

    for (unsigned idx = 0; idx < n; idx++) {
        dist[idx].key = arr[idx];
        dist[idx].dist = INT_MAX;

        auto hashElem = hashTbl.find(arr[idx]);
        if (hashElem == hashTbl.end())  // key not found in cache
            hashTbl.insert({arr[idx], idx});
        else {                          // key found in cache
            int prevIdx = hashElem->second;
            dist[prevIdx].dist = idx;
            hashElem->second = idx;
        }
    }
    return 0;
}

template <typename KeyT, typename D>
int idealCache(const size_t n, const size_t cacheSz, const std::vector<KeyT>& arr) {
    std::vector<distance<KeyT>> dist(n);

    fillDist<KeyT>(dist, arr, n);

    idealCache_t<KeyT, D> cache(cacheSz, 0);

    int hits = 0;
    for (auto elem : dist) {
        int ver = cache.insert(elem);

        if (ver)
            hits++;
    }
    return hits;
}

} // ideal_cache