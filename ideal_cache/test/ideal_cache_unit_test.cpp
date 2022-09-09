#include "ideal_cache.h"
#include <gtest/gtest.h>

TEST(CacheTest, test1) {
    int arr1[] = {2, 2, 1, 3, 3, 4, 1, 5, 6, 2};
    EXPECT_EQ(4, idealCache(10, 3, arr1));
}
 
TEST(CacheTest, test2) {
    int arr2[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    EXPECT_EQ(5, idealCache(10, 5, arr2));
}

TEST(CacheTest, test3) {
    int arr3[] = {4, 7, 3, 6, 85, 34, 6, 8, 5, 3, 4, 7, 8, 6, 4, 4, 5, 6, 7, 8};
    EXPECT_EQ(10, idealCache(20, 5, arr3));
}

TEST(CacheTest, test4) {
    int arr4[] = {1, 2, 3, 4, 5, 6, 1, 2, 7, 8};
    EXPECT_EQ(2, idealCache(10, 5, arr4));
}

TEST(CacheTest, test5) {
    int arr5[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    EXPECT_EQ(32, idealCache(33, 1, arr5));
}

TEST(CacheTest, test6) {
    int arr6[] = {2, 4, 2, 4, 6, 4, 6, 7, 6, 6, 7, 9, 6, 4, 3, 5, 7, 8, 6, 5, 4, 3, 4, 5, 7, 8, 8, 7, 6};
    EXPECT_EQ(17, idealCache(29, 5, arr6));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}