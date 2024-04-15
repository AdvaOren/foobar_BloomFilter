#include "App.h"

/**
 * This function run the entire program.
 * Input: the menu - the coonection to the outside world.
 * Output: none
 * */
void App::run(IMenu* menu)
{
    Factory& factory = Factory::getInstance();
    if (!factory.isBfInit())
    {
        pthread_mutex_t lock;
        pthread_mutex_lock(&lock);
        if (!factory.isBfInit()) {
            factory.createBloomFilter(menu->getInitParm());
            factory.setBfInit();
        }
        pthread_mutex_unlock(&lock);
    }
    BloomFilter *bf = factory.getBloomFilter();
    string result;
    while (true) {
        int task = menu->getNextTask();
        if (task == ERROR)
            break;
        result = bf->bFilter(task,menu->getURL());
        menu->sendResult(result);
    }
}
