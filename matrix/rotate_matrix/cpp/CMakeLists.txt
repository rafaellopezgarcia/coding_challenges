cmake_minimum_required(VERSION 3.10)
project(rotate_matrix) 

add_executable(rotate_matrix)
target_sources(rotate_matrix PRIVATE main.cpp)
set_property(TARGET rotate_matrix PROPERTY CXX_STANDARD 17)
