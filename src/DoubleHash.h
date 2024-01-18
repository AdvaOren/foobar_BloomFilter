//
// Created by danie on 17/01/2024.
//

#ifndef FOOBAR_DT_DOUBLEHASH_H
#define FOOBAR_DT_DOUBLEHASH_H

#include <Ihash.h>
class DoubleHash: public Ihash{
private:
    int size;
public:
    DoubleHash(int size);
    int hash(std::string URL) override;

};


#endif //FOOBAR_DT_DOUBLEHASH_H
