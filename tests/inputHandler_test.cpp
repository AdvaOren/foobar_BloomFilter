#include "gtest/gtest.h"
#include "../src/inputHandler.cpp"

TEST(ParseTest, BasicTest) {
    EXPECT_TRUE(checkURL("www.example.com"));
    EXPECT_TRUE(checkURL("www.example.com0"));
    EXPECT_TRUE(checkURL("www.example sds.com"));
    EXPECT_TRUE(checkURL("www.e.m"));

    EXPECT_FALSE(checkURL(""));
    EXPECT_FALSE(checkURL("ww.example.com"));
    EXPECT_FALSE(checkURL("www.com"));
    EXPECT_FALSE(checkURL(".example.com"));
    EXPECT_FALSE(checkURL("www.example"));
    EXPECT_FALSE(checkURL("www.examplecom"));
    EXPECT_FALSE(checkURL(".www.example.com"));
    EXPECT_FALSE(checkURL("www.example.com."));
}
