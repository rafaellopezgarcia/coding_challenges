cmake_minimum_required(VERSION 3.10)
project(container_with_most_water) 

add_executable(container_with_most_water)
target_sources(container_with_most_water PRIVATE main.cpp)
set_property(TARGET container_with_most_water PROPERTY CXX_STANDARD 17)
