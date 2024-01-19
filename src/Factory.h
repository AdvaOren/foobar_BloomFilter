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

using std::vector;
using std::string;

class Factory
{
public:
    BloomFilter createBloomFilter(vector<int> initialParams);
    IHash* createHashFunction(int type, int size);
    IMenu* createMenu(int type, std::istream& input);
};


#endif //FOOBAR_DT_FACTORY_H
