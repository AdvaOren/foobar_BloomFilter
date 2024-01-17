//
// Created by danie on 17/01/2024.
//

#ifndef FOOBAR_DT_ADDCOMMAND_H
#define FOOBAR_DT_ADDCOMMAND_H
#include "Icommand.h"
using std::string;
class addCommand: public Icommand {
public:
    void execute(string URL, int* array, vector<Ihash*> hashes,
                 vector<string>* blackList) override;
};


#endif //FOOBAR_DT_ADDCOMMAND_H
