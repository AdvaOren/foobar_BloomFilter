#ifndef FOOBAR_TD_INPUTHANDLER_H
#define FOOBAR_TD_INPUTHANDLER_H
#include <iostream>
#include <string>
#include <vector>

#define ERROR -1
#define NUM_OF_HASH_FUNCS 2
#define ALL_THE_NUMBERS "0123456789"
#define MAX_INIT_LINE_SIZE 3

using std::string;
using std::vector;

//This class check validation of the input and manipulate it.
class InputHandler
{
public:
    bool checkURL(string url);
    vector<string> parseLine(string line);
    int getType(string line);
    bool checkInitialLineInput(vector<string> line);
    bool checkLineValidation(string line, int lineType);
    string getURL(string line);

};


#endif //FOOBAR_TD_INPUTHANDLER_H
