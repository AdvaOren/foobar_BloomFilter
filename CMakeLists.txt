cmake_minimum_required(VERSION 3.14)
project("foobar_DT")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL
        https://github.com/google/googletest/archive/03597a01ee50ed
        33e9dfd640b249b4be3799d395.zip
)
enable_testing()
add_subdirectory(../foobar_DT/lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES
        # this is where the code we want to test
        src/BloomFilter.cpp
        src/BloomFilter.h
        )
set(TEST_FILES
        ../foobar_DT/tests/test_main.cpp # this is the main for tests
        # this file contain the tests
        tests/BF_test.cpp src/Ihash.h src/singleHash.cpp src/singleHash.h)


add_executable(CalcTests ${TEST_FILES})
# Link Google Test to the test executable
target_link_libraries(CalcTests PRIVATE gtest gtest_main)
# Include the source directory for tests
target_include_directories(CalcTests PRIVATE ../foobar_DT/src)
include(GoogleTest)
add_test(NAME CalcTests COMMAND CalcTests)
