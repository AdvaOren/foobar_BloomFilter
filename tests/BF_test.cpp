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
/*
TEST(BfTest, BasicTest) {
    vector<IHash*> hashes;
    hashes.push_back(new SingleHash(8));
    map<int,ICommand*> commands;
    commands[1] = new AddCommand();
    commands[2] = new CheckCommand();
    BloomFilter bf(8,commands,hashes);
    EXPECT_FALSE(bf.bFilter(2,""));
}

TEST(BfTest, BasicTest2) {
    BloomFilter bf;
    map<string, string> blackList = map<string,string>();
    int* arr = new int[8];
    for (int i = 0; i < 8; ++i) {
        arr[i] = 0;
    }
    vector<int> hashes = vector<int>();
    hashes.push_back(1);
    bf.addToBlackList("",arr,8,hashes,blackList);
    EXPECT_TRUE(bf.checkIfBlackListed("",arr,8,hashes));
    EXPECT_FALSE(bf.checkIfBlackListed("a",arr,8,hashes));
    bf.addToBlackList("a",arr,8,hashes,blackList);
    EXPECT_TRUE(bf.checkIfBlackListed("a",arr,8,hashes));
}

TEST(ListTest, BasicTest) {
    BloomFilter bf;
    map<string, string> blackList = map<string,string>();
    hash<string> hash;
    vector<int> hashes = vector<int>();
    hashes.push_back(1);
    int* OGblackList = new int[8];
    for (int i = 0; i < 8; ++i) {
        OGblackList[i] = 0;
    }
    bf.addToBlackList("",OGblackList,8,hashes,blackList);
    EXPECT_EQ(OGblackList[6],1);
    bf.addToBlackList("a",OGblackList,8,hashes,blackList);
    EXPECT_EQ(OGblackList[hash("a") % 8],1);
    EXPECT_EQ(OGblackList[hash("a") % 8],1);
}

TEST(MultHash, BasicTest) {
    BloomFilter bf;
    map<string, string> blackList = map<string,string>();
    int* arr = new int[8];
    for (int i = 0; i < 8; ++i) {
        arr[i] = 0;
    }
    vector<int> hashes = vector<int>();
    hashes.push_back(1);
    hashes.push_back(2);
    bf.addToBlackList("www.test.com0",arr,8,hashes,blackList);
    EXPECT_TRUE(bf.checkIfBlackListed("www.test.com0",arr,8,hashes));
    EXPECT_FALSE(bf.checkIfBlackListed("www.false.com0",arr,8,hashes));
}

TEST(BlackListTest,BasicTest) {
    BloomFilter bf;
    int* array = new int[8];
    for (int i = 0; i < 8; ++i) {
        array[i] = 0;
    }
    vector<int> hashes = vector<int>();
    hashes.push_back(1);
    map<string, string> blackList = map<string,string>();
    bf.addToBlackList("URL",array,8,hashes,blackList);
    EXPECT_FALSE(bf.checkForFalsePositive("URL", blackList));
}
*/
TEST(SingleHashTest, BasicTest) {
    SingleHash sH = SingleHash(6);
    int index = sH.hash("");
    EXPECT_EQ(index,std::hash<string>()("") % 6);
}

TEST(DoubleHashTest,BasicTest) {
    DoubleHash dH = DoubleHash(23);
    EXPECT_EQ(dH.hash("www.double.com"),
              std::hash<string>()(std::to_string(std::hash<string>()("www.double.com"))) % 23);
}

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
}

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
    //EXPECT_TRUE(true);
    checkCommand.execute("www.examle.com", array,vec,&vec2);
    delete[] array;
}