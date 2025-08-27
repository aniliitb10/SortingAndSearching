cmake_minimum_required(VERSION 3.13)
project(SortingAndSearching LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure C++ linker is used for linking
set(CMAKE_CXX_LINKER_PREFERENCE_PROPAGATES 1)

# Find required packages
find_package(benchmark REQUIRED)
find_package(GTest REQUIRED)

# Include all source files
file(GLOB SOURCE_FILES "lib/*.cpp")
file(GLOB TEST_FILES "test/*.cpp")

add_executable(SortingAndSearching 
    main.cpp
    ${SOURCE_FILES}
    ${TEST_FILES}
)

# Link against both libraries
target_link_libraries(SortingAndSearching PRIVATE 
    benchmark::benchmark
    GTest::gtest
)