cmake_minimum_required (VERSION 3.16)
project(lfu)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#main
set (SOURCES sources/main.cpp sources/lfu_cache.cpp ../common/common.cpp)

add_executable (${PROJECT_NAME} ${SOURCES})
target_include_directories (${PROJECT_NAME} PRIVATE includes ../common)

add_compile_options (-Werror -Wall -Wextra -Wpedantic)

#tests
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set (TARGET lfu_unit_test)
set (TEST_SOURCES test/lfu_unit_test.cpp sources/lfu_cache.cpp)

add_executable(${TARGET} ${TEST_SOURCES})

target_include_directories (${TARGET} PRIVATE includes)
target_link_libraries (${TARGET} ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)