//
// Created by danie on 17/01/2024.
//

#ifndef FOOBAR_DT_ICOMMAND_H
#define FOOBAR_DT_ICOMMAND_H


#include <string>
#include "Ihash.h"
using std::string;
class Icommand {
public:
    virtual void execute(std::string, int* array, vector<Ihash*> hashes,
                         vector<string>* blackList) = 0;
};


#endif //FOOBAR_DT_ICOMMAND_H
