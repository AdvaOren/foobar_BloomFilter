//
// Created by danie on 17/01/2024.
//

#include "DoubleHash.h"

DoubleHash::DoubleHash(int size) {
    this->size = size;
}
/**
 * returns the result of doublehashing the URL
 * */
int DoubleHash::hash(std::string URL) {
    std::hash<std::string> h;
    return h(std::to_string(h(URL))) % this->size;
}
