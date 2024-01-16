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

class InputHandler
{
public:
    static bool checkURL(string url);
    static vector<string> parseLine(string line);
    static int getType(string line);
    static bool checkInitialLineInput(vector<string> line);
    static bool checkLineValidation(string line, int lineType);
    static string getURL(string line);

};


#endif //FOOBAR_TD_INPUTHANDLER_H
