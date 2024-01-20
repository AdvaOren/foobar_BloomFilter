#ifndef FOOBAR_DT_CHECKCOMMAND_H
#define FOOBAR_DT_CHECKCOMMAND_H
#include "ICommand.h"

//This class is the command check. it's check if the url is blocked.
class CheckCommand: public ICommand {
public:
    void execute(string URL, int* array, vector<IHash*> hashes,
                 vector<string>* blackList) override;
};


#endif //FOOBAR_DT_CHECKCOMMAND_H
