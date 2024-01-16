#include "gtest/gtest.h"
#include "../src/InputHandler.h"

TEST(ParseTest, BasicTest) {
    InputHandler tester;
    EXPECT_TRUE(tester.checkURL("www.example.com"));
    EXPECT_TRUE(tester.checkURL("www.example.com0"));
    EXPECT_TRUE(tester.checkURL("www.example sds.com"));
    EXPECT_TRUE(tester.checkURL("www.e.m"));

    EXPECT_FALSE(tester.checkURL(""));
    EXPECT_FALSE(tester.checkURL("ww.example.com"));
    EXPECT_FALSE(tester.checkURL("www.com"));
    EXPECT_FALSE(tester.checkURL(".example.com"));
    EXPECT_FALSE(tester.checkURL("www.example"));
    EXPECT_FALSE(tester.checkURL("www.examplecom"));
    EXPECT_FALSE(tester.checkURL(".www.example.com"));
    EXPECT_FALSE(tester.checkURL("www.example.com."));
}
