#ifndef FOOBAR_DT_ADDCOMMAND_H
#define FOOBAR_DT_ADDCOMMAND_H
#include "ICommand.h"

using std::string;

//This class is the command add. it is blocking urls.
class AddCommand: public ICommand {
public:
    void execute(string URL, int* array, vector<IHash*> hashes,
                 vector<string>* blackList) override;
};


#endif //FOOBAR_DT_ADDCOMMAND_H
