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
    EXPECT_EQ(tester.getType("www.text.com"),ERROR);

    EXPECT_NE(tester.getType("a"),1);
    EXPECT_NE(tester.getType("a 1"),1);
    EXPECT_NE(tester.getType("a"),2);
    EXPECT_NE(tester.getType("a 2"),2);
}

TEST(ValidInitialLine, BasicTest) {
    InputHandler tester;
    vector<string> line0 {"8" ,"2"};
    EXPECT_TRUE(tester.checkInitialLineInput(line0));

    vector<string> line1 {"888" ,"1"};
    EXPECT_TRUE(tester.checkInitialLineInput(line1));

    vector<string> line2 {"10" ,"1" ,"2"};
    EXPECT_TRUE(tester.checkInitialLineInput(line2));

    vector<string> line3 {"125" ,"2" ,"1"};
    EXPECT_TRUE(tester.checkInitialLineInput(line3));

    vector<string> line4 {"a" ,"4" ,"1" ,"3" ,"5"};
    EXPECT_FALSE(tester.checkInitialLineInput(line4));

    vector<string> line5 {"a"};
    EXPECT_FALSE(tester.checkInitialLineInput(line5));

    vector<string> line6 {"4"};
    EXPECT_FALSE(tester.checkInitialLineInput(line6));

    vector<string> line7 {"4" ,"a"};
    EXPECT_FALSE(tester.checkInitialLineInput(line7));

    vector<string> line8 {"456489456" ,"1a"};
    EXPECT_FALSE(tester.checkInitialLineInput(line8));

    vector<string> line9 {};
    EXPECT_FALSE(tester.checkInitialLineInput(line9));

    vector<string> line10 {"8" ,"3"};
    EXPECT_FALSE(tester.checkInitialLineInput(line10));

    vector<string> line11 {"8" ,"1", "2", "3"};
    EXPECT_FALSE(tester.checkInitialLineInput(line11));

    vector<string> line12 {"8" ,"1", "3"};
    EXPECT_FALSE(tester.checkInitialLineInput(line12));
}
