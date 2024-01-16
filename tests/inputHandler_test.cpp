#include "gtest/gtest.h"
#include "../src/InputHandler.cpp"
#include <vector>

using std::vector;
using std::string;

TEST(CheckURLTest, BasicTest) {
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

TEST(ParseLine, BasicTest) {
    InputHandler tester;
    vector<string> r1{"8","1","2"};
    EXPECT_EQ(tester.parseLine("8 1 2"),r1);

    vector<string> r2{"aa", "ss", "dd"};
    EXPECT_EQ(tester.parseLine("aa ss dd"),r2);

    vector<string> r3{"8"};
    EXPECT_EQ(tester.parseLine("8"),r3);

    vector<string> r4{"128", "1"};
    EXPECT_EQ(tester.parseLine("128 1"),r4);

    vector<string> r5{"125", "aa", "dd5", "58!"};
    EXPECT_EQ(tester.parseLine("125 aa dd5 58!"),r5);

    vector<string> r6{"8", "1", "2", "12", "55", "8878"};
    EXPECT_EQ(tester.parseLine("8 1 2 12 55 8878"),r6);

    vector<string> r7;
    EXPECT_EQ(tester.parseLine(""),r7);
}

TEST(GetType, BasicTest) {
    InputHandler tester;
    EXPECT_EQ(tester.getType("1 www.example.com"),1);
    EXPECT_EQ(tester.getType("1 8"),1);
    EXPECT_EQ(tester.getType("1 .example.com"),1);
    EXPECT_EQ(tester.getType("1 com"),1);
    EXPECT_EQ(tester.getType("1 8 2 5"),1);
    EXPECT_EQ(tester.getType("1 0"),1);
    EXPECT_EQ(tester.getType("2 did it work?"),2);
    EXPECT_EQ(tester.getType("2 0 1 2"),2);
    EXPECT_EQ(tester.getType("2 0 aa ss"),2);
    EXPECT_EQ(tester.getType("2 www.example.com"),2);
    EXPECT_EQ(tester.getType("2 www.example.com0"),2);
    EXPECT_EQ(tester.getType("2 www.text.com"),2);
}

