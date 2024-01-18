//
// Created by danie on 18/01/2024.
//

#include "CheckCommand.h"
#include <iostream>
void CheckCommand::execute(string URL, int *array, vector<Ihash *> hashes,
                           vector<string>* blackList) {
    for (Ihash* h: hashes) {
        if (array[h->hash(URL)] == 0) {
            std::cout << "false" << std::endl;
            return;
        }
    }
    std::cout << "true";
    for (string s: *blackList) {
        if (!s.compare(URL)) {
            std::cout << std::endl;
            return;
        }
    }
    std::cout << " false" << std::endl;
}
