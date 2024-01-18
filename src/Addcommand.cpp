//
// Created by danie on 17/01/2024.
//

#include "AddCommand.h"

/**
 * name:execute
 * input:URL,array of indexes,vector of hash funcs, vector of blacklisted strings
 * output: marks the hashed indexes on the arrray and adds the URL to vector
 * */
void Addcommand::execute(string URL, int *array, vector<Ihash*> hashes, vector<string>* blackList) {
    for (Ihash* h: hashes) {
            array[h->hash(URL)] = 1;
    }
    blackList->push_back(URL);
}
