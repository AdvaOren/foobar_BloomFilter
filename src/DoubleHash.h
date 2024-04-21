#ifndef FOOBAR_DT_DOUBLEHASH_H
#define FOOBAR_DT_DOUBLEHASH_H

#include "IHash.h"

//This class perform hash function twice on the input.
class DoubleHash: public IHash{
private:
    int size;
public:
    DoubleHash(int size);
    int hash(std::string URL) override;

};


#endif //FOOBAR_DT_DOUBLEHASH_H
