#ifndef FOOBAR_DT_IHASH_H
#define FOOBAR_DT_IHASH_H
#include <vector>
#include <string>

using std::vector;

//This is interface for all the hash classes.
class IHash {
public:
   virtual int hash(std::string URL) = 0;
   virtual ~IHash() = default;
};


#endif //FOOBAR_DT_IHASH_H
