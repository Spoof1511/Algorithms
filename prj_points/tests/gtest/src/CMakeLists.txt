add_executable(xipoint_test_start 
    point_test.cpp
    point_array_test.cpp
    ${CMAKE_SOURCE_DIR}/../../src/xipoint.cpp
    ${CMAKE_SOURCE_DIR}/../../src/xipoint.h
)

target_link_libraries(xipoint_test_start ${gtest_LIB} ${gtest_main_LIB})
#target_link_libraries(xipoint_test_start ${gtest_main_LIB})
