#include <gtest/gtest.h>
#include <vector>
#include "BloomFilter.cpp"
#include "singleHash.h"
#include "doubleHash.h"
#include "addCommand.h"

using std::vector;
using std::hash;
TEST(BfTest, BasicTest) {
    map<string, string> blackList = map<string,string>();
    int* arr = new int[8];
    for (int i = 0; i < 8; ++i) {
        arr[i] = 0;
    }
    vector<int> hashes = vector<int>();
    hashes.push_back(1);
    EXPECT_FALSE(checkIfBlackListed("", arr, 8, hashes));
}

TEST(BfTest, BasicTest2) {
    map<string, string> blackList = map<string,string>();
    int* arr = new int[8];
    for (int i = 0; i < 8; ++i) {
        arr[i] = 0;
    }
    vector<int> hashes = vector<int>();
    hashes.push_back(1);
    addToBlackList("",arr,8,hashes,blackList);
    EXPECT_TRUE(checkIfBlackListed("",arr,8,hashes));
    EXPECT_FALSE(checkIfBlackListed("a",arr,8,hashes));
    addToBlackList("a",arr,8,hashes,blackList);
    EXPECT_TRUE(checkIfBlackListed("a",arr,8,hashes));
}

TEST(ListTest, BasicTest) {
    map<string, string> blackList = map<string,string>();
    hash<string> hash;
    vector<int> hashes = vector<int>();
    hashes.push_back(1);
    int* OGblackList = new int[8];
    for (int i = 0; i < 8; ++i) {
        OGblackList[i] = 0;
    }
    addToBlackList("",OGblackList,8,hashes,blackList);
    EXPECT_EQ(OGblackList[6],1);
    addToBlackList("a",OGblackList,8,hashes,blackList);
    EXPECT_EQ(OGblackList[hash("a") % 8],1);
    EXPECT_EQ(OGblackList[hash("a") % 8],1);
}

TEST(MultHash, BasicTest) {
    map<string, string> blackList = map<string,string>();
    int* arr = new int[8];
    for (int i = 0; i < 8; ++i) {
        arr[i] = 0;
    }
    vector<int> hashes = vector<int>();
    hashes.push_back(1);
    hashes.push_back(2);
    addToBlackList("www.test.com0",arr,8,hashes,blackList);
    EXPECT_TRUE(checkIfBlackListed("www.test.com0",arr,8,hashes));
    EXPECT_FALSE(checkIfBlackListed("www.false.com0",arr,8,hashes));
}

TEST(BlackListTest,BasicTest) {
    int* array = new int[8];
    for (int i = 0; i < 8; ++i) {
        array[i] = 0;
    }
    vector<int> hashes = vector<int>();
    hashes.push_back(1);
    map<string, string> blackList = map<string,string>();
    addToBlackList("URL",array,8,hashes,blackList);
    EXPECT_FALSE(checkForFalsePositive("URL", blackList));
}

TEST(SingleHashTest, BasicTest) {
    singleHash sH = singleHash(6);
    int index = sH.hash("");
    EXPECT_EQ(index,std::hash<string>()("") % 6);
}

TEST(DoubleHashTest,BasicTest) {
    doubleHash dH = doubleHash(23);
    EXPECT_EQ(dH.hash("www.double.com"),
              std::hash<string>()(std::to_string(std::hash<string>()("www.double.com"))) % 23);
}

TEST(CommandAddTest, BasicTest) {
    int* array = new int[8];
    for (int i = 0; i < 8; ++i) {
        array[i] = 0;
    }
    int index = std::hash<string>()("www.example.com") % 8;
    addCommand add = addCommand();
    Ihash* sH = new singleHash(8);
    vector<Ihash*> vec = vector<Ihash*>();
    vec.push_back(sH);
    vector<string> vec2 = vector<string>();
    add.execute("www.example.com", array,vec,&vec2);
    EXPECT_EQ(array[index],1);
}