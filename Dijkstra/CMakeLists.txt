cmake_minimum_required(VERSION 3.6)
project(Deekstra)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp RailSystem.cpp City.h Service.h services.txt)
add_executable(Deekstra ${SOURCE_FILES})