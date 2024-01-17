//
// Created by danie on 17/01/2024.
//

#ifndef FOOBAR_DT_BLOOMFILTER_H
#define FOOBAR_DT_BLOOMFILTER_H

#include <string>

using std::string;
bool checkIfBlackListed(string URL);
void addToBlackList(string URL);
int* getBlackList();

#endif //FOOBAR_DT_BLOOMFILTER_H
