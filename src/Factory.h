#ifndef FOOBAR_DT_FACTORY_H
#define FOOBAR_DT_FACTORY_H
#include <vector>
#include <map>
#include "IMenu.h"
#include "Menu.h"
#include "ICommand.h"
#include "AddCommand.h"
#include "CheckCommand.h"
#include "IHash.h"
#include "SingleHash.h"
#include "DoubleHash.h"
#include "BloomFilter.h"

#define CONSOLE_MENU 0

using std::vector;
using std::string;

//This a factory class that help to create objects.
class Factory
{
public:
    BloomFilter createBloomFilter(vector<int> initialParams);
    IHash* createHashFunction(int type, int size);
    IMenu* createMenu(int type);
};


#endif //FOOBAR_DT_FACTORY_H
