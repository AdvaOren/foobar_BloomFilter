

#include "BloomFilter.h"
#include <string>
#include <utility>
using std::string;
using std::hash;
/*
 * bloomFilter: checkIfBlackListed
 * gets a URL and checks if it is in the blackList with hash funcs
 * */
bool BloomFilter::checkIfBlackListed(string URL, int* array, int size, vector<int> hashes) {
    hash<string> hash;
    for (int hashe : hashes) {
        //hashe == 1 means single hash
        if (hashe == 1) {
            if (array[hash(URL) % size] == 0) {
                //if an index is 0 the URL cant be in the list
                return false;
            }
        }
        //hashe == 2 means double hash
        if (hashe == 2) {
            if (array[hash(std::to_string(hash(URL))) % size] == 0) {
                return false;
            }
        }
    }
    return true;
}
/**
 * BloomFilter: addToBlackList
 * adds a URL to the blackList by marking the hashed indexes and
 * adding it to the map
 * */
void BloomFilter::addToBlackList(string URL, int* array, int size, vector<int> hashes,
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
/**
 * bloomFilter; check for false positive
 * in the case that an URL got hashed to marked indexes
 * check the map for the URL if it is there return false
 * (it is not a false positive) o.w return true
 * */
bool BloomFilter::checkForFalsePositive(string URL, map<string,string>& blackList) {
    if (blackList.find(URL) != blackList.end()) {
        return false;
    }
    return true;
}

BloomFilter::BloomFilter(int sizeBitsArray,map<int, ICommand*> commands,vector<IHash*> hashes)
{
    this->sizeBitsArray = sizeBitsArray;
    this->bitsArray = new int[sizeBitsArray];
    this->blackList = new vector<string>();
    for (int i = 0; i < sizeBitsArray; ++i)
    {
        bitsArray[i] = 0;
    }
    this->commands = std::move(commands);
    this->hashes = std::move(hashes);
}

BloomFilter::~BloomFilter()
{
    for (IHash* hash: this->hashes) {
        delete hash;
    }
    for(auto & command : commands) {
        delete command.second;
    }
    delete this->bitsArray;
}

void BloomFilter::bFilter(int task, string URL)
{
    commands[task]->execute(URL,bitsArray,hashes,blackList);
}
