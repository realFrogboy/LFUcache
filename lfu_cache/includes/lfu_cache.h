#pragma once

#include <stdio.h>
#include <assert.h>
#include <list>
#include <unordered_map>
#include <iterator>

template <typename T, typename FreqNode, typename KeyT = int>
struct setNode_t {
    T data;
    KeyT key;

    using freqNodeIt = typename std::list<FreqNode>::iterator;
    freqNodeIt freqNode;

    setNode_t(T d, KeyT k, freqNodeIt iter) : data(d), key(k), freqNode(iter) {};
};

template <typename T, typename KeyT = int>
struct freqNode_t {
    int freq;
    std::list<setNode_t<T, freqNode_t<T>>> lst;

    freqNode_t(int fr) : freq(fr) {};
};

template <typename T, typename KeyT = int>
struct cache_t {
    size_t cpty;
    size_t size;
    std::list<freqNode_t<T>> freqLst;

    using lstIt = typename std::list<setNode_t<T, freqNode_t<T>>>::iterator;
    std::unordered_map<KeyT, lstIt> hashTbl;

    cache_t(size_t capacity, size_t sz) : cpty(capacity), size(sz) {}; // ctor

    int insert(KeyT key) {
        auto elem = hashTbl.find(key);

        if (elem != hashTbl.end()) 
            return 1;

        size++;

        if (size > cpty) {
            freqNode_t<int> lessFreq = freqLst.front();
            auto node = lessFreq.lst.begin();  // !!!
            int key = node->key;

            auto elem = hashTbl.find(key);
            hashTbl.erase(elem);
            lessFreq.lst.pop_front(); // !!!

            if (!lessFreq.lst.size()) 
                freqLst.pop_front();

            size--;
        }

        auto lessFreq = freqLst.begin();
        if (lessFreq->freq != 1) {
            freqNode_t<int> newNode(1);
            freqLst.push_front(newNode);
        }

        std::list<freqNode_t<int>>::iterator node = freqLst.begin();
        setNode_t<int, freqNode_t<int>> newNode(key, key, node);    

        node->lst.push_front(newNode);
        auto newNodeIt = node->lst.begin();

        hashTbl.insert({key, newNodeIt});

        return 0;
    }

    int access(KeyT key) {
        auto elem = hashTbl.find(key);

        auto freq = elem->second->freqNode;
        auto freqNext = std::next(freq, 1);

        if ((freqNext == freqLst.end()) || (freq->freq != (freqNext->freq + 1))) {
            freqNode_t<int> newNode(freq->freq + 1);    
            freqLst.insert(freqNext, newNode);
        }

        freq->lst.erase(elem->second);
        freqNext = std::next(freq, 1);

        if (!freq->lst.size()) 
            freqLst.erase(freq);

        setNode_t<int, freqNode_t<int>> newNode(key, key, freqNext);    

        freqNext->lst.push_front(newNode);

        return 0;
    }
};

int lfuCache(const size_t n, const size_t cacheSz, const int *arr);