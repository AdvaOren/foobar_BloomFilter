#ifndef FOOBAR_DT_SINGLEHASH_H
#define FOOBAR_DT_SINGLEHASH_H
#include "IHash.h"

//This class perform one time hash on the input
class SingleHash: public IHash {
private:
    int size;
public:
    SingleHash(int size);
    int hash(std::string URL) override;
};


#endif //FOOBAR_DT_SINGLEHASH_H
