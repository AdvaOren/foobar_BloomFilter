#include <gtest/gtest.h>

TEST(BfTest, BasicTest) {
    EXPECT_FALSE(checkIfBlackListed(""));
}