cmake_minimum_required(VERSION 3.24)
project(SimplifiedPageRank)

set(CMAKE_CXX_STANDARD 14)

add_executable(SimplifiedPageRank main.cpp AdjacencyList.cpp AdjacencyList.h test.cpp)
