#ifndef FOOBAR_DT_ICOMMAND_H
#define FOOBAR_DT_ICOMMAND_H
#include <string>
#include "IHash.h"

using std::string;

//This is an interface for all the commands.
class ICommand {
public:
    virtual string execute(std::string, int* array, vector<IHash* > hashes, vector<string>* blackList) = 0;
    virtual ~ICommand() = default;
};


#endif //FOOBAR_DT_ICOMMAND_H
