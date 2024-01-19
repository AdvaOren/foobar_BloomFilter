//
// Created by danie on 17/01/2024.
//

#ifndef FOOBAR_DT_ADDCOMMAND_H
#define FOOBAR_DT_ADDCOMMAND_H
#include "ICommand.h"
using std::string;
class AddCommand: public ICommand {
public:
    void execute(string URL, int* array, vector<IHash*> hashes,
                 vector<string>* blackList) override;
};


#endif //FOOBAR_DT_ADDCOMMAND_H
