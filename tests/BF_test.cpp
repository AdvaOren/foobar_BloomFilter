#include <gtest/gtest.h>
#include <vector>
#include "BloomFilter.h"
using std::vector;
using std::hash;
TEST(BfTest, BasicTest) {
    int* blacklist = new int(8);
    EXPECT_FALSE(checkIfBlackListed("", blacklist,8));
}

TEST(BfTest, BasicTest2) {
    int* blackList = new int(8);
    for (int i = 0; i < 8; ++i) {
        blackList[i] = 0;
    }
    addToBlackList("",blackList,8);
    EXPECT_TRUE(checkIfBlackListed("",blackList,8));
    EXPECT_FALSE(checkIfBlackListed("a",blackList,8));
    addToBlackList("a",blackList,8);
    EXPECT_TRUE(checkIfBlackListed("a",blackList,8));
}

TEST(ListTest, BasicTest) {
    hash<string> hash;
    int* OGblackList = new int(8);
    int *OGblacklist2 = OGblackList;
    for (int i = 0; i < 8; ++i) {
        OGblackList[i] = 0;
    }
    addToBlackList("",OGblackList,8);
    int* blackList = getBlackList(OGblackList);
    EXPECT_EQ(blackList[6],1);
    addToBlackList("a",OGblacklist2,8);
    int* blackList2 = getBlackList(OGblacklist2);
    EXPECT_EQ(blackList2[hash("a") % 8],1);
    EXPECT_EQ(blackList[hash("a") % 8],1);
    delete blackList;
}

TEST(MultHash, BasicTest) {
    int* blackList = new int (8);
    vector<int> hashes = vector<int>();
    hashes.push_back(1);
    hashes.push_back(2);
    addToBlackList("www.test.com",blackList,8,hashes);
    EXPECT_TRUE(checkIfBlackListed("www.test.com",blackList,8,hashes));
    EXPECT_FALSE(checkIfBlackListed("www.false.com",blackList,8,hashes));
}