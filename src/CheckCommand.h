//
// Created by danie on 18/01/2024.
//

#ifndef FOOBAR_DT_CHECKCOMMAND_H
#define FOOBAR_DT_CHECKCOMMAND_H
#include "Icommand.h"

class CheckCommand: public Icommand {
public:
    void execute(string URL, int* array, vector<Ihash*> hashes,
                 vector<string>* blackList) override;
};


#endif //FOOBAR_DT_CHECKCOMMAND_H
