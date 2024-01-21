#include "Factory.h"

/**
 * This function return an object of BloomFilter.
 * Input: inital data of the BloomFilter object.
 * Output: the BloomFilter object.
 */
BloomFilter Factory::createBloomFilter(vector<int> initialParams)
{
    map<int, ICommand*> commands;
    vector<IHash*> hashes;
    //create the commands.
    commands[1] = new AddCommand();
    commands[2] = new CheckCommand();
    //create the hashes function.
    for (int i = 1; i < initialParams.size(); ++i)
    {
        hashes.push_back(createHashFunction(initialParams[i],initialParams[0]));
    }
    return BloomFilter(initialParams[0], commands, hashes);
}

/**
 * This function create a Hash object
 * Input: type of hash object and the bits arry size
 * Output: the hash object
 */
IHash *Factory::createHashFunction(int type, int size)
{
    if (type == 1)
        return new SingleHash(size);
    else if (type == 2)
        return new DoubleHash(size);
    return nullptr;
}

/**
 * This function create a Menu object
 * Input: the menu type
 * Output: the menu object
 */
IMenu *Factory::createMenu(int type)
{
    if (type == CONSOLE_MENU)
        return new Menu();
    return nullptr;
}
