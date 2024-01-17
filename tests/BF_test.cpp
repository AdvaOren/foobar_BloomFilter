#include <gtest/gtest.h>
#include "BloomFilter.h"

using std::hash;
TEST(BfTest, BasicTest) {
    EXPECT_FALSE(checkIfBlackListed(""));
}

TEST(BfTest, BasicTest2) {
    addToBlackList("");
    EXPECT_TRUE(checkIfBlackListed(""));
    EXPECT_FALSE(checkIfBlackListed("a"));
    addToBlackList("a");
    EXPECT_TRUE(checkIfBlackListed("a"));
}

TEST(ListTest, BasicTest) {
    hash<string> hash;
    addToBlackList("");
    int* blackList = getBlackList();
    EXPECT_EQ(blackList[6],1);
    addToBlackList("a");
    int* blackList2 = getBlackList();
    EXPECT_EQ(blackList2[hash("a") % 8],1);
    EXPECT_EQ(blackList[hash("a") % 8],1);
    delete blackList;
    delete blackList2;
}