#include "SingleHash.h"

/**
 * singleHash: hash
 * returns a single use of hash func on given URL
 * */
int SingleHash::hash(std::string URL){
   std::hash<std::string> h;
    return h(URL) % this->size;
}

/**
 * This function is the constructor of the class
 * @param size the size of the bits array
 */
SingleHash::SingleHash(int size) {
    this->size = size;
}
