//
// Created by danie on 17/01/2024.
//

#ifndef FOOBAR_DT_IHASH_H
#define FOOBAR_DT_IHASH_H
#include <vector>
#include <string>

using std::vector;

class IHash {
public:
   virtual int hash(std::string URL) = 0;
};


#endif //FOOBAR_DT_IHASH_H
