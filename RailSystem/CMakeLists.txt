cmake_minimum_required(VERSION 3.6)
project(RailSystem)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp RailSystem.cpp )
add_executable(RailSystem ${SOURCE_FILES})