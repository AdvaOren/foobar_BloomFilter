#ifndef FOOBAR_TD_APP_H
#define FOOBAR_TD_APP_H
#include <iostream>
#include "IMenu.h"
#include "BloomFilter.h"
#include "Factory.h"

using std::string;

//This class run the program.
class App
{
public:
    static void run(IMenu* menu);
};


#endif //FOOBAR_TD_APP_H
