cmake_minimum_required (VERSION 3.5.0)

set(ADVENT_CXX_FLAGS -Wall -Wextra -pedantic)

project (AdventOfCode2015 CXX)

set(CMAKE_CXX_FLAGS "-O3 -march=native")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)
add_subdirectory(src)
