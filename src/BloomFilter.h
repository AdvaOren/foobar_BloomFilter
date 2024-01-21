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
using std::hash;

//This class handle the block sites.
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
};
#endif //FOOBAR_DT_BLOOMFILTER_H
