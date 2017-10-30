cmake_minimum_required(VERSION 3.6)
project(SkipHW)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp JournalNetActivity.h JournalNetActivity.hpp NetActivity.cpp NetActivity.h OrderedList.h OrderedList.hpp SkipList.h SkipList.hpp TimeStamp.cpp TimeStamp.h)
add_executable(SkipHW ${SOURCE_FILES})