#include "App.h"

/**
 * This function run the entire program.
 * Input: the menu - the coonection to the outside world.
 * Output: none
 * */
void App::run(IMenu* menu)
{
    BloomFilter bf(factory.createBloomFilter(menu->getInitParm()));
    while (true) {
        int task = menu->getNextTask();
        bf.bFilter(task,menu->getURL());
    }
    delete menu;
}
