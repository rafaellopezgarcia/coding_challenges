cmake_minimum_required(VERSION 3.10)
project(sort_list) 

add_executable(sort_list)
target_sources(sort_list PRIVATE main.cpp linked_list.hpp)
set_property(TARGET sort_list PROPERTY CXX_STANDARD 17)
