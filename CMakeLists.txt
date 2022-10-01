cmake_minimum_required (VERSION 3.16)
project(comparator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES comparator.cpp)

add_executable (${PROJECT_NAME} ${SOURCES})
target_include_directories (${PROJECT_NAME} PRIVATE lfu_cache/includes ideal_cache/includes common costom_type)

add_subdirectory (lfu_cache)
add_subdirectory (ideal_cache)

add_compile_options (-Werror -Wall -Wextra -Wpedantic)