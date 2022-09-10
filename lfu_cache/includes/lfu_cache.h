#pragma once

#include <stdio.h>
#include <assert.h>
#include <list>
#include <unordered_map>
#include <iterator>
#include <vector>

template <typename T, typename FreqNode, typename KeyT = int>
struct setNode_t {
    T data;
    KeyT key;

    using freqNodeIt = typename std::list<FreqNode>::iterator;
    freqNodeIt freqNode;

    setNode_t(T d, KeyT k, freqNodeIt iter) : data(d), key(k), freqNode(iter) {};  //ctor
};

template <typename T, typename KeyT = int>
struct freqNode_t {
    int freq;
    std::list<setNode_t<T, freqNode_t<T>>> lst;

    freqNode_t(int fr) : freq(fr) {};   //ctor
};

template <typename T, typename KeyT = int>
struct cache_t {
    size_t cpty;
    size_t size;
    std::list<freqNode_t<T>> freqLst;

    using lstIt = typename std::list<setNode_t<T, freqNode_t<T>>>::iterator;
    std::unordered_map<KeyT, lstIt> hashTbl;

    cache_t(size_t capacity, size_t sz) : cpty(capacity), size(sz) {}; // ctor

    int insert(const KeyT key) {
        auto hashElem = hashTbl.find(key);

        if (hashElem != hashTbl.end())      // key founded in cache
            return 1;
                                            // key not founded
        size++;
        if (size > cpty) {
            auto lessFreq = freqLst.begin();
            auto setElem = lessFreq->lst.begin(); 
            int key = setElem->key;

            auto elemToDel = hashTbl.find(key);
            hashTbl.erase(elemToDel);
            lessFreq->lst.pop_front();

            if (!lessFreq->lst.size()) 
                freqLst.pop_front();

            size--;
        }

        auto lessFreq = freqLst.begin();
        if (lessFreq->freq != 1) {
            freqNode_t<int> newNode(1);
            freqLst.push_front(newNode);
        }

        std::list<freqNode_t<int>>::iterator freqNode = freqLst.begin();
        setNode_t<int, freqNode_t<int>> newNode(key, key, freqNode);    

        freqNode->lst.push_front(newNode);
        auto newNodeIt = freqNode->lst.begin();

        hashTbl.insert({key, newNodeIt});

        return 0;
    }

    int access(const KeyT key) {
        auto hashElem = hashTbl.find(key);
        auto setElem = hashElem->second;

        auto freqElem = setElem->freqNode;
        auto freqNext = std::next(freqElem, 1);

        if ((freqNext == freqLst.end()) || ((freqElem->freq + 1) != freqNext->freq)) {
            freqNode_t<int> newNode(freqElem->freq + 1);    
            freqLst.insert(freqNext, newNode);
        }

        
        freqElem->lst.erase(setElem);
        hashTbl.erase(hashElem);
        freqNext = std::next(freqElem, 1);

        if (!freqElem->lst.size()) 
            freqLst.erase(freqElem);

        setNode_t<int, freqNode_t<int>> newNode(key, key, freqNext);    

        freqNext->lst.push_front(newNode);
        auto newHashElem = freqNext->lst.begin();
        hashTbl.insert({key, newHashElem});

        return 0;
    }
};

int lfuCache(const size_t n, const size_t cacheSz, const std::vector<int>& arr);