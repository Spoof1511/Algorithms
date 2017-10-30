cmake_minimum_required(VERSION 3.6)
project(grid_kek)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp grid.h grid.cpp)
add_executable(grid_kek ${SOURCE_FILES})