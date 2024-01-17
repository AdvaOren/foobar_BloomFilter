//
// Created by danie on 17/01/2024.
//

#ifndef FOOBAR_DT_BLOOMFILTER_H
#define FOOBAR_DT_BLOOMFILTER_H

#include <string>
#include <vector>
using std::vector;
using std::string;
bool checkIfBlackListed(string URL, int * array, int size, vector<int> hashes);
void addToBlackList(string URL, int* array, int size, vector<int> hashes,
                    vector<string>& blackList);
int* getBlackList(int * blackList);
bool checkForFalsePositive(string URL,vector<string>& blackList);
#endif //FOOBAR_DT_BLOOMFILTER_H
