cmake_minimum_required (VERSION 3.16)
project(ideal_cache)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#main
set (SOURCES sources/main.cpp sources/ideal_cache.cpp ../common/common.cpp)

add_executable (${PROJECT_NAME} ${SOURCES})
target_include_directories (${PROJECT_NAME} PRIVATE includes ../common)

add_compile_options (-Werror -Wall -Wextra -Wpedantic)

#tests
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set (TEST_SOURCES test/ideal_cache_unit_test.cpp sources/ideal_cache.cpp)

add_executable(ideal_cache_unit_test ${TEST_SOURCES})

target_include_directories (ideal_cache_unit_test PRIVATE includes)
target_link_libraries(ideal_cache_unit_test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)