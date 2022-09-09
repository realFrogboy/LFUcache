cmake_minimum_required (VERSION 3.16)
project(comporator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES comporator.cpp lfu_cache/sources/lfu_cache.cpp ideal_cache/sources/ideal_cache.cpp common/common.cpp)

add_executable (${PROJECT_NAME} ${SOURCES})
target_include_directories (${PROJECT_NAME} PRIVATE lfu_cache/includes ideal_cache/includes common)

add_compile_options (-Werror -Wall -Wextra -Wpedantic)