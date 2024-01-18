#include "Menu.h"

/**
 * This is the constructor for the class. cthe c'tor read the first line from user.
 *  input: none
 *  Output: none
 */
 //for now, for the tests the input is from file
Menu::Menu(std::istream& input)
{
    //read the input until the initial line is legal
    do
    {
        //getline(std::cin,currLine);
        std::getline(input,currLine);
        currLine.erase(currLine.begin() + currLine.length()-1);
    } while (!inputHandler.checkLineValidation(currLine,INIT_LINE_TYPE));
}

/**
 * This function return the url in the line
 *  input: none
 *  Output: the url
 */
std::string Menu::getURL()
{
    return inputHandler.getURL(currLine);
}

/**
 * This function return the initial parameters
 *  input: none
 *  Output: the parameters
 */
std::vector<int> Menu::getInitParm()
{
    vector<string> paramsString = inputHandler.parseLine(currLine);
    vector<int> params;
    char * temp;
    //convert the params from string to int
    for (int i = 0; i < paramsString.size(); ++i)
    {
        params.push_back((int)strtol(paramsString[i].c_str(),&temp,DECIMAL));
    }
    return params;
}

/**
 * This function return the next type of task
 *  input: none
 *  Output: the task
 */
//for now, for the tests the input is from file
int Menu::getNextTask(std::istream& input)
{
    //read the input until the initial line is legal
    do
    {
        //getline(std::cin,currLine);
        std::getline(input,currLine);
        currLine.erase(currLine.begin() + currLine.length()-1);
    } while (!inputHandler.checkLineValidation(currLine,inputHandler.getType(currLine)));
    return inputHandler.getType(currLine);
}
