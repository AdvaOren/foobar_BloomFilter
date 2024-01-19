//
// Created by danie on 17/01/2024.
//

#ifndef FOOBAR_DT_ICOMMAND_H
#define FOOBAR_DT_ICOMMAND_H


#include <string>
#include "IHash.h"
using std::string;
class ICommand {
public:
    virtual void execute(std::string, int* array, vector<IHash* > hashes,
                         vector<string>* blackList) = 0;
    virtual ~ICommand() = default;
};


#endif //FOOBAR_DT_ICOMMAND_H
