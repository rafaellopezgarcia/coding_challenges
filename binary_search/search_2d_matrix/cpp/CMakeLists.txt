cmake_minimum_required(VERSION 3.10)
project(search_2d_matrix)

add_executable(solution1)
target_sources(solution1 PRIVATE ./main.cpp)

set_property(TARGET solution1 PROPERTY CXX_STANDARD 20)