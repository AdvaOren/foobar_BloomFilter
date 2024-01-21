#include <gtest/gtest.h>
#include <vector>
#include "BloomFilter.cpp"
#include "SingleHash.cpp"
#include "DoubleHash.cpp"
#include "AddCommand.cpp"
#include "CheckCommand.cpp"

using std::vector;
using std::hash;
using std::map;

//This test check the function hash() in the SingleHash class
TEST(SingleHashTest, BasicTest) {
    SingleHash sH = SingleHash(6);
    int index = sH.hash("");
    EXPECT_EQ(index,std::hash<string>()("") % 6);
}

//This test check the function hash() in the DoubleHash class
TEST(DoubleHashTest,BasicTest) {
    DoubleHash dH = DoubleHash(23);
    EXPECT_EQ(dH.hash("www.double.com"),
              std::hash<string>()(std::to_string(std::hash<string>()("www.double.com"))) % 23);
}

//This test check the function execute() in the AddCommand class
TEST(CommandAddTest, BasicTest) {
    int* array = new int[8];
    for (int i = 0; i < 8; ++i) {
        array[i] = 0;
    }
    int index = std::hash<string>()("www.example.com") % 8;
    AddCommand add = AddCommand();
    IHash* sH = new SingleHash(8);
    vector<IHash*> vec = vector<IHash*>();
    vec.push_back(sH);
    vector<string> vec2 = vector<string>();
    add.execute("www.example.com", array,vec,&vec2);
    EXPECT_EQ(array[index],1);
    delete[] array;
    delete sH;
}

//This test check the function execute() in the CheckCommand class
TEST(CommandCheckTest, BasicTest) {
    int* array = new int[8];
    for (int i = 0; i < 8; ++i) {
        array[i] = 0;
    }
    AddCommand add = AddCommand();
    IHash* sH = new SingleHash(8);
    vector<IHash*> vec = vector<IHash*>();
    vec.push_back(sH);
    vector<string> vec2 = vector<string>();
    add.execute("www.example.com", array,vec,&vec2);
    CheckCommand checkCommand = CheckCommand();
    checkCommand.execute("www.example.com", array,vec,&vec2);
    checkCommand.execute("www.examle.com", array,vec,&vec2);
    //need to print:
    //true true
    //false
    delete[] array;
    delete sH;
}