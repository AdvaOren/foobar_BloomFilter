#include "BloomFilter.h"
#include <utility>
#include "ICommand.h"
#include "map"


/**
 * This function is the constructor of the object
 * Input: the size of the bits array, the command and the hashes functions.
 * */
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

/**
 * This function is the destructor of the object
 * Input: none
 * */
BloomFilter::~BloomFilter()
{
    //delete the hashes functions.
    for (IHash* hash: this->hashes) {
        delete hash;
    }
    //delete the commands.
    for(auto & command : commands) {
        delete command.second;
    }
    delete this->bitsArray;
}

/**
 * This function is the filtering function
 * Input: the command task and th url.
 * */
void BloomFilter::bFilter(int task, string URL)
{
    commands[task]->execute(URL,bitsArray,hashes,blackList);
}
