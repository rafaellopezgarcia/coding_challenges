cmake_minimum_required(VERSION 3.10)
project(kth_largest_element) 

add_executable(kth_largest_element)
target_sources(kth_largest_element PRIVATE main.cpp)
set_property(TARGET kth_largest_element PROPERTY CXX_STANDARD 17)
