#include <gtest/gtest.h>
#include "BloomFilter.h"

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