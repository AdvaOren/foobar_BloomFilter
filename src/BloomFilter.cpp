

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
                    vector<string>& blackList) {
    hash<string> hash;
    for (int hashe : hashes) {
        if (hashe == 1) {
            array[hash(URL) % size] = 1;
        }
        if (hashe == 2) {
            array [hash(std::to_string(hash(URL))) % size] = 1;
        }
    }
    blackList.push_back(URL);

}
int* getBlackList(int *blackList) {
    return blackList;
}
bool checkForFalsePositive(string URL, vector<string>& blackList) {
    for (string s:blackList) {
        if (!URL.compare(s)) {
            return false;
        }
    }
    return true;
}
