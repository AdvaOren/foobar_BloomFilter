//
// Created by danie on 17/01/2024.
//

#include "SingleHash.h"

/**
 * singleHash: hash
 * returns a single use of hash func on given URL
 * */
int SingleHash::hash(std::string URL){
   std::hash<std::string> h;
    return h(URL) % this->size;
}

SingleHash::SingleHash(int size) {
    this->size = size;
}
