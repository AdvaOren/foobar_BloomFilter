#include "Menu.h"

Menu::Menu(std::istream& input)
{
    do
    {
        //getline(std::cin,currLine);
        std::getline(input,currLine);
        currLine.erase(currLine.begin() + currLine.length()-1);
    } while (!inputHandler.checkLineValidation(currLine,INIT_LINE_TYPE));
}


std::string Menu::getURL()
{
    return inputHandler.getURL(currLine);
}

std::vector<int> Menu::getInitParm()
{
    vector<string> paramsString = inputHandler.parseLine(currLine);
    vector<int> params;
    char * temp;
    for (int i = 0; i < paramsString.size(); ++i)
    {
        params.push_back((int)strtol(paramsString[i].c_str(),&temp,DECIMAL));
    }
    return params;
}

int Menu::getNextTask(std::istream& input)
{
    do
    {
        //getline(std::cin,currLine);
        std::getline(input,currLine);
        currLine.erase(currLine.begin() + currLine.length()-1);
    } while (!inputHandler.checkLineValidation(currLine,inputHandler.getType(currLine)));
    return inputHandler.getType(currLine);
}
