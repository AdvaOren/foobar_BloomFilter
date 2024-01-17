//
// Created by danie on 17/01/2024.
//

#include "singleHash.h"


vector<int> singleHash::hash(std::string URL){
   std::hash<std::string> h;
   vector<int> vec = vector<int>();
   vec.push_back(h(URL) % this->size);
    return vec;
}

singleHash::singleHash(int size) {
    this->size = size;
}
