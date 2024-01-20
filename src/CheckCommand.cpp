#include "CheckCommand.h"
#include <iostream>

/***
 * name: execute:
 * input: URL, array of blacklisted indexes a vector of hash funcs and a vector
 * of blacklisted strings
 * output: hashes the URL checks if it is blacklisted:
 * in the case that it is we might have False Positive and check on the vector
 * */
void CheckCommand::execute(string URL, int *array, vector<IHash *> hashes,
                           vector<string>* blackList) {
    //check with the hash function if the url is blocked.
    for (IHash* h: hashes) {
        if (array[h->hash(URL)] == 0) {
            std::cout << "false" << std::endl;
            return;
        }
    }
    std::cout << "true";
    //check in the blackList if the url is blocked.
    for (string s: *blackList) {
        if (!s.compare(URL)) {
            std::cout << " true" << std::endl;
            return;
        }
    }
    std::cout << " false" << std::endl;
}
