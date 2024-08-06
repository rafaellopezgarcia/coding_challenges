cmake_minimum_required(VERSION 3.10)
project(search_insert_position) 

add_executable(search_insert_position)
target_sources(search_insert_position PRIVATE main.cpp)
set_property(TARGET search_insert_position PROPERTY CXX_STANDARD 17)
