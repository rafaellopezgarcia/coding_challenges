cmake_minimum_required(VERSION 3.10)
project(h_index) 

add_executable(h_index)
target_sources(h_index PRIVATE main.cpp)
set_property(TARGET h_index PROPERTY CXX_STANDARD 17)
