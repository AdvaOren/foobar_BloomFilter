#include "InputHandler.h"



/** The function take a complete line and parse it by ' '
 * Input: the whole line
 * Output: the parts of the line*/
vector <string> InputHandler::parseLine(string line)
{
    vector<string> arguments = vector<string>();
    int pos = 0;
    while ((pos = line.find(' ')) != string::npos) {
        //take the data from the start to the first ' '
        string argument = line.substr(0, pos);
        //add the data
        arguments.push_back(argument);
        //erase the data from the line
        line.erase(0, pos + 1);
    }
    //add the last argument
    if (line.length() != 0)
    {
        arguments.push_back(line);
    }
    return arguments;
}

/** The function return the type of the line
 * Input: the whole line
 * Output: the type. ERROR=-1 will return if type not found */
int InputHandler::getType(string line)
{
    if (line.length() == 0) {
        return ERROR;
    }
    string type = parseLine(line)[0];
    //check the
    if (type.find_first_not_of("0123456789") != string::npos) {
        return ERROR;
    }
    return atoi(type.c_str());
}

/** The function check if the argument match the initial line
 * Input: line arguments
 * Output: match or not */
bool InputHandler::checkInitialLineInput(vector<string> line)
{
    if (line.size() < NUM_OF_HASH_FUNCS)
    {
        return false;
    }
    //check if the size of the bit array is a number.
    if (line[0].find_first_not_of(ALL_THE_NUMBERS) != string::npos)
    {
        return false;
    }
    //check if the size of the bit array is a positive number.
    char * temp;
    int arraySize = (int)strtol(line[0].c_str(),&temp,10);
    if (arraySize <=0 )
    {
        return false;
    }
    //check if the hash arguments are 1 or 2
    for (int i = 1; i < line.size(); ++i)
    {
        if (line[i] != "1" && line[i] != "2")
            return false;
    }
    return true;
}

/** The function check if a line is match the line type
 * Input: the whole line to check and the type of the line
 * Output: Does the line match the type format */
bool InputHandler::checkLineValidation(string line, int lineType)
{
    vector<string> arguments = parseLine(line);
    switch (lineType)
    {
        //this is the case of the inital line in the code
        case 0:
            return checkInitialLineInput(arguments);
        //this is the case of option 1 - adding to black list
        case 1:
            return arguments.size() >= 2 && getType(arguments[0]) == 1;
        //this is the case of option 2 - check  if site is in the blacklist
        case 2:
            return arguments.size() >= 2 && getType(arguments[0]) == 2;
    }
    return false;
}

/**
 * this function return the url from a line
 * Input: the whole line
 * Output: the url
 */
string InputHandler::getURL(string line)
{
    vector<string> arguments = parseLine(line);
    string url = arguments[1];
    //handle the case that the url contain space in it.
    if (arguments.size() > 2) {
        for (int i = 2; i < arguments.size(); ++i)
        {
            url = url + " " + arguments[i];
        }
    }
    return url;
}

std::vector<int> InputHandler::getInitParm(string line)
{
    vector<string> paramsString = parseLine(line);
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
