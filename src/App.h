#ifndef FOOBAR_TD_APP_H
#define FOOBAR_TD_APP_H
#include <iostream>
#include "IMenu.h"
#include "BloomFilter.h"
#include "Factory.h"

using std::string;

class App
{
private:
    Factory factory;
public:
    void run(IMenu* menu, std::istream& input);
};


#endif //FOOBAR_TD_APP_H
