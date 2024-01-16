#ifndef FOOBAR_TD_INPUTHANDLER_H
#define FOOBAR_TD_INPUTHANDLER_H
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class InputHandler
{
public:
    bool checkURL(string url);
    vector<string> parseLine(string line);

};


#endif //FOOBAR_TD_INPUTHANDLER_H
