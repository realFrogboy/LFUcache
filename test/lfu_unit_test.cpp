#include "lfu_unit_test.h"
#include <gtest/gtest.h>

TEST(CacheTest, test1) {
    int arr1[] = {2, 2, 1, 3, 3, 4, 1, 5, 6, 2};
    EXPECT_EQ(3, lfuCache(10, 3, arr1));
}

TEST(CacheTest, test2) {
    int arr2[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    EXPECT_EQ(5, lfuCache(10, 5, arr2));
}

TEST(CacheTest, test3) {
    int arr3[] = {4, 7, 3, 6, 85, 34, 6, 8, 5, 3, 4, 7, 8, 6, 4, 4, 5, 6, 7, 8};
    EXPECT_EQ(9, lfuCache(20, 5, arr3));
}

TEST(CacheTest, test4) {
    int arr4[] = {1, 2, 3, 4, 5, 6, 1, 2, 7, 8};
    EXPECT_EQ(2, lfuCache(10, 5, arr4));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}