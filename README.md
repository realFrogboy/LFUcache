# LFUcache
LFUcache for the 1st task of the C++ cource.

## The description of the algorythm

### LFU
LFU means least frequently used. The element which was requested the least number of times removed from the list.
More information about implementation is on the [website](http://dhruvbird.com/lfu.pdf "website").

### Ideal cache
If we knew the requests in advance, then if we needed to delete an element from the cache, we would choose the one that would be encountered later than other elements. Such an algorithm cann't be implemented in real life, but in the conditions of this task, we know in advance which requests will come, so we can use this:
1. Specify the distance to the next similar element for each request using a hash table. Asymptotic complexity O(n).
2. When deleting an element, you just need to look through all the cache elements and knowing the distance, delete the element that will occur later than the rest of the elements. Asymptotic complexity O(k), k - number of elements in cache.

## Installation
1. Make sure that CMake and git is installed on your computer.
2. Then you need to run:            

        git clone "git@github.com:realFrogboy/LFUcache.git"


## Build

### LFU
1. Then go to the "LFUcache\lfu_cache" directory:

        cd LFUcache\lfu_cache

2. Create a new folder "build" and go to it:

        mkdir build
        cd build

3. Run CMake:

        cmake ../
        cmake --build ./

4. The program in the file called "lfu".

### Ideal cache          
1. Then go to the "LFUcache\ideal_cache" directory.
2. Create a new folder "build" and go to it.
3. Run CMake.
4. The program in the file called "ideal_cache".

### Comporator
1. Then go to the "LFUcache" directory.
2. Create a new folder "build" and go to it.
3. Run CMake.
4. The program in the file called "comporator".

## Tests
To run the test you should:
1. Go to folder "build".
2. Run CTest:

        ctest

The tests are done using Google Test.


