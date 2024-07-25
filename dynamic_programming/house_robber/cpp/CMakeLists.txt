cmake_minimum_required(VERSION 3.10)
project(house_robber) 

add_executable(house_robber)
target_sources(house_robber PRIVATE main.cpp)
set_property(TARGET house_robber PROPERTY CXX_STANDARD 17)
