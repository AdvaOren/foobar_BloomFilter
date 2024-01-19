#ifndef FOOBAR_TD_IMENU_H
#define FOOBAR_TD_IMENU_H
#include <iostream>
#include <vector>

#define INIT_LINE_TYPE 0

//this is interface for all the menus
class IMenu
{
public:
    virtual std::string getURL() = 0;
    virtual std::vector<int> getInitParm() = 0;
    virtual int getNextTask(std::istream& input) = 0;
    virtual ~IMenu() = default;
};


#endif //FOOBAR_TD_IMENU_H
