cmake_minimum_required (VERSION 3.16)
project(ideal_cache)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (CMAKE_BUILD_TYPE Debug)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#main
set (SOURCES sources/main.cpp sources/ideal_cache.cpp)

add_executable (${PROJECT_NAME} ${SOURCES})
target_include_directories (${PROJECT_NAME} PRIVATE includes)

add_compile_options (-g -Werror -Wall -Wextra -Wpedantic)

#tests
enable_testing()

set (TEST_SOURCES test/ideal_cache_unit_test.cpp sources/ideal_cache.cpp)

add_executable(ideal_cache_unit_test ${TEST_SOURCES})
target_include_directories (ideal_cache_unit_test PRIVATE includes)
target_link_libraries(ideal_cache_unit_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(ideal_cache_unit_test)