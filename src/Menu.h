#ifndef FOOBAR_TD_MENU_H
#define FOOBAR_TD_MENU_H
#include <iostream>
#include <vector>
#include "IMenu.h"
#include "InputHandler.h"
#include <fstream>
#include <string>

#define DECIMAL 10

using std::string;
using std::vector;

class Menu : IMenu
{
private:
    string currLine;
    InputHandler inputHandler;
public:
    Menu(std::istream& input);
    std::string getURL() override;
    std::vector<int> getInitParm() override;
    int getNextTask(std::istream& input) override;
};


#endif //FOOBAR_TD_MENU_H
