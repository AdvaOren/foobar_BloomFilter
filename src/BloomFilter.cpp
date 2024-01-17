

#include "BloomFilter.h"
#include <string>
using std::string;
using std::hash;
bool checkIfBlackListed(string URL, int* array, int size, vector<int> hashes) {
    hash<string> hash;
    for (int hashe : hashes) {
        if (hashe == 1) {
            if (array[hash(URL) % size] == 0) {
                return false;
            }
        }
        if (hashe == 2) {
            if (array[hash(std::to_string(hash(URL))) % size] == 0) {
                return false;
            }
        }
    }
    return true;
}
void addToBlackList(string URL, int* array, int size, vector<int> hashes,
                    map<string,string>& blackList) {
    hash<string> hash;
    for (int hashe : hashes) {
        if (hashe == 1) {
            array[hash(URL) % size] = 1;
        }
        if (hashe == 2) {
            array [hash(std::to_string(hash(URL))) % size] = 1;
        }
    }
    blackList[URL] = URL;

}
bool checkForFalsePositive(string URL, map<string,string>& blackList) {
    if (blackList.find(URL) != blackList.end()) {
        return false;
    }
    return true;
}
