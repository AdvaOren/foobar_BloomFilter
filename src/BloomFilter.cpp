

#include "BloomFilter.h"
#include <string>
using std::string;
using std::hash;
bool checkIfBlackListed(string URL,int* blackList, int size) {
    hash<string> hash;
    return blackList[hash(URL) % size] == 1;
}
void addToBlackList(string URL,int* blackList,int size) {
    hash<string> hash;
    blackList[hash(URL) % size] = 1;
    return;
}
int* getBlackList(int *blackList) {
    return blackList;
}