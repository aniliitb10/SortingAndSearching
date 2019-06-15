cmake_minimum_required(VERSION 3.13)
project(SortingAndSearching)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC" )
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

file (GLOB SOURCE_FILES "lib/*.cpp")

file(GLOB TestSource "test/*.cpp")

add_executable(SortingAndSearching main.cpp ${SOURCE_FILES} ${TestSource})
target_link_libraries(SortingAndSearching gtest benchmark pthread)