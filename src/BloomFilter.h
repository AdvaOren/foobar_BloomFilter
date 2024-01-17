//
// Created by danie on 17/01/2024.
//

#ifndef FOOBAR_DT_BLOOMFILTER_H
#define FOOBAR_DT_BLOOMFILTER_H
#include <map>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::map;
bool checkIfBlackListed(string URL, int * array, int size, vector<int> hashes);
void addToBlackList(string URL, int* array, int size, vector<int> hashes,
                    map<string,string>& blackList);
bool checkForFalsePositive(string URL,map<string,string>& blackList);
#endif //FOOBAR_DT_BLOOMFILTER_H
