cmake_minimum_required(VERSION 3.13)
project(SortingAndSearching)

set(CMAKE_CXX_STANDARD 17)

file (GLOB SOURCE_FILES "lib/*.cpp")

set (GTEST_LIB_PATH "/home/anil/lib/googletest-release-1.8.0/googletest/libgtest.a")
set (GTEST_INCLUDE_PATH "/home/anil/lib/googletest-release-1.8.0/googletest/include/")

#set (BENCHMARK_LIB_PATH "/home/anil/lib/google-benchmark-1.5/lib/libbenchmark.a")
#set (BENCHMARK_INCLUDE_PATH "/home/anil/lib/google-benchmark-1.5/include/")

file(GLOB TestSource "test/*.cpp")
include_directories( ${GTEST_INCLUDE_PATH} ${BENCHMARK_INCLUDE_PATH})

add_executable(SortingAndSearching main.cpp ${SOURCE_FILES} ${TestSource})
target_link_libraries(SortingAndSearching ${GTEST_LIB_PATH} pthread)
# target_link_libraries(SortingAndSearching ${GTEST_LIB_PATH} ${BENCHMARK_LIB_PATH} pthread)