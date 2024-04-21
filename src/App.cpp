#include "App.h"

/**
 * This function run the entire program.
 * Input: the menu - the coonection to the outside world.
 * Output: none
 * */
void App::run(IMenu* menu)
{
    pthread_mutex_t lock;

    Factory& factory = Factory::getInstance();
    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    if (!factory.isBfInit())
    {
        pthread_mutex_lock(&lock);
        if (!factory.isBfInit()) {
            factory.createBloomFilter(menu->getInitParm());
            factory.setBfInit();
        }
        pthread_mutex_unlock(&lock);
    }
    // Destroy the mutex when no longer needed
    pthread_mutex_destroy(&lock);
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
