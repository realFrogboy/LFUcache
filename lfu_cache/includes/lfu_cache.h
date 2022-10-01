#pragma once

#include <stdio.h>
#include <assert.h>
#include <list>
#include <unordered_map>
#include <iterator>
#include <vector>
#include "costom.h"

namespace lfu_cache {

template <typename D, typename FreqNode>
struct setNode_t {
    using freqNodeIt = typename std::list<FreqNode>::iterator;

    D data;
    freqNodeIt freqNode;

    setNode_t(D d, freqNodeIt iter) : data(d), freqNode(iter) {};
};

template <typename D, typename KeyT>
struct freqNode_t {
    int freq;
    std::list<setNode_t<D, freqNode_t<D, KeyT>>> lst;

    freqNode_t(int fr) : freq(fr) {};
};

template <typename KeyT, typename D>
struct cache_t {
    using lstIt = typename std::list<setNode_t<D, freqNode_t<D, KeyT>>>::iterator;

    size_t cpty;
    size_t size;
    std::list<freqNode_t<D, KeyT>> freqLst;
    std::unordered_map<KeyT, lstIt> hashTbl;

    cache_t(size_t capacity, size_t sz) : cpty(capacity), size(sz) {};

    int insert(const KeyT key) {
        auto hashElem = hashTbl.find(key);
        if (hashElem != hashTbl.end())      // key found in cache
            return 1;
                                            // key not found
        size++;
        if (size > cpty) {
            auto lessFreq = freqLst.begin();
            auto setElem = lessFreq->lst.begin(); 
            int key = setElem->data.getKey();

            auto elemToDel = hashTbl.find(key);
            hashTbl.erase(elemToDel);
            lessFreq->lst.pop_front();

            if (!lessFreq->lst.size()) 
                freqLst.pop_front();

            size--;
        }

        costom_type::page_t page(key);
        page.slowGet(key);

        auto lessFreq = freqLst.begin();
        if (lessFreq->freq != 1) {
            freqNode_t<D, KeyT> newNode(1);
            freqLst.push_front(newNode);
        }

        auto freqNode = freqLst.begin();
        setNode_t<D, freqNode_t<D, KeyT>> newNode(page, freqNode);    

        freqNode->lst.push_front(newNode);
        auto newNodeIt = freqNode->lst.begin();

        hashTbl.insert({key, newNodeIt});

        return 0;
    }

    int access(const KeyT key) {
        auto hashElem = hashTbl.find(key);
        auto setElem = hashElem->second;

        auto freqElem = setElem->freqNode;
        auto freqNext = std::next(freqElem);

        if ((freqNext == freqLst.end()) || ((freqElem->freq + 1) != freqNext->freq)) {
            freqNode_t<D, KeyT> newNode(freqElem->freq + 1);    
            freqLst.insert(freqNext, newNode);
        }

        auto tmpData = *(setElem);
        freqElem->lst.erase(setElem);
        hashTbl.erase(hashElem);
        freqNext = std::next(freqElem);

        if (!freqElem->lst.size()) 
            freqLst.erase(freqElem);

        setNode_t<D, freqNode_t<D, KeyT>> newNode(tmpData.data, freqNext);    

        freqNext->lst.push_front(newNode);
        auto newHashElem = freqNext->lst.begin();
        hashTbl.insert({key, newHashElem});

        return 0;
    }
};

template <typename KeyT, typename D>
int lfuCache(const size_t n, const size_t cacheSz, const std::vector<KeyT>& arr) {
    cache_t<KeyT, D> cache(cacheSz, 0);

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