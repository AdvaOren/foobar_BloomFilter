//
// Created by danie on 17/01/2024.
//

#include "singleHash.h"


int singleHash::hash(std::string URL){
   std::hash<std::string> h;
    return h(URL) % this->size;
}

singleHash::singleHash(int size) {
    this->size = size;
}
