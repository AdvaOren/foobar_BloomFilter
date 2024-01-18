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
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES
        # this is where the code we want to test
        src/InputHandler.cpp
        src/InputHandler.h
        src/Menu.h
        src/Menu.cpp

        )
set(TEST_FILES
        tests/test_main.cpp # this is the main for tests
        # this file contain the tests

        tests/inputHandler_test.cpp
        tests/menu_test.cpp
        )


add_executable(BFTest ${TEST_FILES})
# Link Google Test to the test executable
target_link_libraries(BFTest PRIVATE gtest gtest_main)
# Include the source directory for tests
target_include_directories(BFTest PRIVATE src)
include(GoogleTest)
add_test(NAME BFTest COMMAND BFTest)
