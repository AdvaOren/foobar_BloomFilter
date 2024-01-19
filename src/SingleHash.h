//
// Created by danie on 17/01/2024.
//

#ifndef FOOBAR_DT_SINGLEHASH_H
#define FOOBAR_DT_SINGLEHASH_H
#include "IHash.h"

class SingleHash: public IHash {
private:
    int size;
public:
    SingleHash(int size);
    int hash(std::string URL);
};


#endif //FOOBAR_DT_SINGLEHASH_H
