#include "ideal_cache.h"
#include <gtest/gtest.h>

namespace ideal_cache_tests {

TEST(CacheTest, test1) {
    std::vector<int> arr1 = {2, 2, 1, 3, 3, 4, 1, 5, 6, 2};
    int res = ideal_cache::idealCache<int, costom_type::page_t>(10, 3, arr1);
    EXPECT_EQ(4, res);
}
 
TEST(CacheTest, test2) {
    std::vector<int> arr2 = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    int res = ideal_cache::idealCache<int, costom_type::page_t>(10, 5, arr2);
    EXPECT_EQ(5, res);
}

TEST(CacheTest, test3) {
    std::vector<int> arr3 = {4, 7, 3, 6, 85, 34, 6, 8, 5, 3, 4, 7, 8, 6, 4, 4, 5, 6, 7, 8};
    int res = ideal_cache::idealCache<int, costom_type::page_t>(20, 5, arr3);
    EXPECT_EQ(11, res);
}

TEST(CacheTest, test4) {
    std::vector<int> arr4 = {1, 2, 3, 4, 5, 6, 1, 2, 7, 8};
    int res = ideal_cache::idealCache<int, costom_type::page_t>(10, 5, arr4);
    EXPECT_EQ(2, res);
}

TEST(CacheTest, test5) {
    std::vector<int> arr5 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int res = ideal_cache::idealCache<int, costom_type::page_t>(34, 1, arr5);
    EXPECT_EQ(33, res);
}

TEST(CacheTest, test6) {
    std::vector<int> arr6 = {2, 4, 2, 4, 6, 4, 6, 7, 6, 6, 7, 9, 6, 4, 3, 5, 7, 8, 6, 5, 4, 3, 4, 5, 7, 8, 8, 7, 6};
    int res = ideal_cache::idealCache<int, costom_type::page_t>(29, 5, arr6);
    EXPECT_EQ(20, res);
}

} // ideal_cache_tests

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}