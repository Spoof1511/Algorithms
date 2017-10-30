add_executable(safe_array_test_start 
    safearray_test.cpp
    subject_test.cpp
    ${CMAKE_SOURCE_DIR}/../../src/safearray.h
    ${CMAKE_SOURCE_DIR}/../../src/safearray.hpp
    ${CMAKE_SOURCE_DIR}/../../src/subject.h
    ${CMAKE_SOURCE_DIR}/../../src/subject.cpp
)

target_link_libraries(safe_array_test_start ${gtest_LIB} ${gtest_main_LIB})
