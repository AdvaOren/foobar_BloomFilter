#include "Menu.h"

/**
 * This is the constructor for the class. the c'tor read the first line from user.
 *  input: none
 *  Output: none
 */
 //function for the tests. The input is from file
Menu::Menu(std::istream& input)
{
    //read the input until the initial line is legal
    do
    {
        std::getline(input,currLine);
        if (currLine[currLine.length()-1] == '\r')
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
        int type = (int)strtol(paramsString[i].c_str(),&temp,DECIMAL);
        bool typeExists = false;
        for (int j = 1; j < params.size(); ++j)
        {
            if (params[j] == type) {
                typeExists = true;
                break;
            }
        }
        if (!typeExists)
            params.push_back(type);
    }
    return params;
}

/**
 * This function return the next type of task
 *  input: none
 *  Output: the task
 */
//function for the tests. The input is from file
int Menu::getNextTask(std::istream& input)
{
    //read the input until the initial line is legal
    do
    {
        std::getline(input,currLine);
        if (currLine[currLine.length()-1] == '\r')
            currLine.erase(currLine.begin() + currLine.length()-1);
    } while (!inputHandler.checkLineValidation(currLine,inputHandler.getType(currLine)));
    return inputHandler.getType(currLine);
}

/**
 * This is the constructor for the class. the c'tor read the first line from user.
 *  input: none
 *  Output: none
 */
Menu::Menu()
{
    //read the input until the initial line is legal
    do
    {
        getline(std::cin,currLine);
    } while (!inputHandler.checkLineValidation(currLine,INIT_LINE_TYPE));
}

/**
 * This function return the next type of task
 *  input: none
 *  Output: the task
 */
int Menu::getNextTask()
{
    //read the input until the initial line is legal
    do
    {
        getline(std::cin,currLine);
    } while (!inputHandler.checkLineValidation(currLine,inputHandler.getType(currLine)));
    return inputHandler.getType(currLine);
}
