#include "App.h"

void App::run(IMenu* menu,std::istream& input)
{
    BloomFilter bf(factory.createBloomFilter(menu->getInitParm()));
    while (true) {
        bf.bFilter(menu->getNextTask(input),menu->getURL());
    }
    delete menu;
}
