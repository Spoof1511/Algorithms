cmake_minimum_required(VERSION 3.6)
project(SemTask)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp fifo.cpp job.cpp simulator.cpp event.cpp)


add_executable(SemTask ${SOURCE_FILES})