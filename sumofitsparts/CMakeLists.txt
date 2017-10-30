cmake_minimum_required(VERSION 3.6)
project(sumofitspartsDZ)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp parts.h parts.cpp)
add_executable(sumofitspartsDZ ${SOURCE_FILES})