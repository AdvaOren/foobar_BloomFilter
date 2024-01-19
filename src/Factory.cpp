#include "Factory.h"

BloomFilter Factory::createBloomFilter(vector<int> initialParams)
{
    map<int, ICommand*> commands;
    vector<IHash*> hashes;
    commands[1] = new AddCommand();
    commands[2] = new CheckCommand();
    for (int i = 1; i < initialParams.size(); ++i)
    {
        hashes.push_back(createHashFunction(initialParams[i],initialParams[0]));
    }
    return BloomFilter(initialParams[0], commands, hashes);
}

IHash *Factory::createHashFunction(int type, int size)
{
    if (type == 1)
        return new SingleHash(size);
    else if (type == 2)
        return new DoubleHash(size);
    return nullptr;
}

IMenu* Factory::createMenu(int type,std::istream& input)
{
    if (type == 0)
        return new Menu(input);
    return nullptr;
}
