#pragma once

#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <unordered_map>
#include <vector>
#include <map>

template <typename KeyT = int>
struct distance {
    KeyT key;
    int dist;
};

template <typename KeyT = int>
struct idealCache_t {
    size_t capacity;
    size_t size;
    std::multimap<int, KeyT> cacheElems;
    using mapIt = typename std::multimap<int, KeyT>::iterator;

    std::unordered_map<KeyT, mapIt> hashTbl;

    idealCache_t(size_t cpty, size_t sz) : capacity(cpty), size(sz) {};    //ctor

    int insert(const distance<KeyT> elem) {
        auto hashElem = hashTbl.find(elem.key);
        if (hashElem != hashTbl.end()) {  //  key founded
            cacheElems.erase(hashElem->second);
            hashTbl.erase(hashElem);
            auto iter = cacheElems.insert({elem.dist, elem.key});
            hashTbl.insert({elem.key, iter});
            return 1;
        }

// key not founded
        size++;
        if (size > capacity) {
            auto maxIter = std::prev(cacheElems.end());
            auto deletedKey = maxIter->second;
            cacheElems.erase(maxIter);
            auto deletedIter = hashTbl.find(deletedKey);
            hashTbl.erase(deletedIter);
            size--;
        }


        auto iter = cacheElems.insert({elem.dist, elem.key});
        hashTbl.insert({elem.key, iter});
        return 0;
    }
};

int idealCache(const size_t n, const size_t cacheSz, const std::vector<int>& arr);

template <typename KeyT = int>
int fillDist(std::vector<distance<KeyT>>& dist, const std::vector<int>& arr, const size_t n);