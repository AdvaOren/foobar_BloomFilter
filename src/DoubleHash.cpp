#include "DoubleHash.h"

/**
 * This function is the constructor of the class
 * Input: the size of the bits array.
 */
DoubleHash::DoubleHash(int size) {
    this->size = size;
}

/**
 * This function returns the result of hashing the URL
 * Input: the url
 * Output: the result
 * */
int DoubleHash::hash(std::string URL) {
    std::hash<std::string> h;
    return h(std::to_string(h(URL))) % this->size;
}
