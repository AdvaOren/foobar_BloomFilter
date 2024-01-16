#include "InputHandler.h"

/* The function check if a given URL is legal
* Input: the url
* Output: legal or not*/
bool InputHandler::checkURL(string url)
{
    // check that the url has the minimum chars. for example www.a.a
    if (url.length() < 7)
    {
        return false;
    }
    //check the 'www' in the beginning
    if (url[0] != 'w' || url[1] != 'w' || url[2] != 'w')
    {
        return false;
    }
    //check that there is a dot after the 'www' and then the domain start
    if (url[3] != '.' || url[4] == '.')
    {
        return false;
    }
    //We already check that the firs dot appear after the 'www'
    bool dotAppearTwice = false;
    for (int i = 5; i < url.length()-1; ++i)
    {
        if (url[i] == '.') {
            dotAppearTwice = true;
        }
    }
    //check that the url not ending with '.'
    if (url[url.length()-1] == '.')
    {
        return false;
    }
    return dotAppearTwice;
}

/* The function take a complete line and parse it by ' '
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

/* The function return the type of the line
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

/* The function check if the argument match the initial line
 * Input: line arguments
 * Output: match or not */
bool InputHandler::checkInitialLineInput(vector<string> line)
{
    if (line.size() < NUM_OF_HASH_FUNCS || line.size() > MAX_INIT_LINE_SIZE)
    {
        return false;
    }
    //check if the size of the bit array is a number.
    if (line[0].find_first_not_of(ALL_THE_NUMBERS) != string::npos)
    {
        return false;
    }
    //check if the hash arguments are 1 or 2
    if (!(line[1].compare("1") == 0 || line[1].compare("2") == 0))
    {
        return false;
    }
    if (line.size() == MAX_INIT_LINE_SIZE)
    {
        if (!(line[2].compare("1") == 0 || line[2].compare("2") == 0))
        {
            return false;
        }
        //check if the hash arguments are not the same
        if (line[1].compare(line[2]) == 0)
        {
            return false;
        }
    }
    return true;
}

/* The function check if a line is match the line type
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
            if (arguments.size() != 2)
            {
                return false;
            }
            return getType(arguments[0]) == 1 && checkURL(arguments[1]);
        //this is the case of option 2 - check  if site is in the blacklist
        case 2:
            if (arguments.size() != 2)
            {
                return false;
            }
            return getType(arguments[0]) == 2 && checkURL(arguments[1]);
    }
    return false;
}
