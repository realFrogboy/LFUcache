#pragma once

#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <unordered_map>
#include <vector>

template <typename KeyT = int>
struct distance {
    KeyT key;
    int dist;
};

template <typename KeyT = int>
struct idealCache_t {
    size_t capacity;
    size_t size;
    std::unordered_map<KeyT, int> hashTbl;

    idealCache_t(size_t cpty, size_t sz) : capacity(cpty), size(sz) {};    //ctor

    int insert(const distance<KeyT> elem) {
        auto hashElem = hashTbl.find(elem.key);
        if (hashElem != hashTbl.end())    //  key founded
            return 1;

// key not founded
        size++;
        if (size > capacity) {
            int max = 0;
            auto maxIter = hashTbl.begin();
            for (auto iter = hashTbl.begin(); iter != hashTbl.end(); iter++)
                if (iter->second > max) {
                    max = iter->second;
                    maxIter = iter;
                }
            hashTbl.erase(maxIter);
            size--;
        }

        hashTbl.insert({elem.key, elem.dist});
        return 0;
    }


    int decDist(std::vector<distance<KeyT>> arr) {
        for (auto iter = hashTbl.begin(); iter != hashTbl.end(); iter++) {
            iter->second--;
            if (iter->second == 0) 
                iter->second = arr[iter->first].dist;
        }
        return 0;
    }
};

int idealCache(const size_t n, const size_t cacheSz, const std::vector<int>& arr);

template <typename KeyT = int>
int fillDist(std::vector<distance<KeyT>>& dist, const std::vector<int>& arr, const size_t n);