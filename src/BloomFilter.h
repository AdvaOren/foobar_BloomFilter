//
// Created by danie on 17/01/2024.
//

#ifndef FOOBAR_DT_BLOOMFILTER_H
#define FOOBAR_DT_BLOOMFILTER_H
#include <map>
#include <string>
#include <vector>
#include "ICommand.h"
#include "IHash.h"

using std::vector;
using std::string;
using std::map;

class BloomFilter
{
private:
    int* bitsArray;
    int sizeBitsArray;
    vector<string>* blackList;
    map<int, ICommand*> commands;
    vector<IHash*> hashes;

public:
    BloomFilter(int sizeBitsArray,map<int, ICommand*> commands,vector<IHash*> hashes);
    void bFilter(int task, string URL);
    ~BloomFilter();
    bool checkIfBlackListed(string URL, int *array, int size, vector<int> hashess);
    void addToBlackList(string URL, int *array, int size, vector<int> hashess, map<string, string> &blackList);
    bool checkForFalsePositive(string URL, map<string, string> &blackList);
};
#endif //FOOBAR_DT_BLOOMFILTER_H
