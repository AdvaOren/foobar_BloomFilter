

#include "BloomFilter.h"
#include <string>
#include <utility>
#include "ICommand.h"
#include "map"
using std::string;
using std::hash;

BloomFilter::BloomFilter(int sizeBitsArray,map<int,ICommand*> commands,vector<IHash*> hashes)
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
