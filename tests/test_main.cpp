#include <gtest/gtest.h>
#include <iostream>
using std::hash;
using std::string;
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}