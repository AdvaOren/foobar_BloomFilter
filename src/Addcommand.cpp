//
// Created by danie on 17/01/2024.
//

#include "AddCommand.h"


void Addcommand::execute(string URL, int *array, vector<Ihash*> hashes, vector<string>* blackList) {
    for (Ihash* h: hashes) {
            array[h->hash(URL)] = 1;
    }
    blackList->push_back(URL);
}
