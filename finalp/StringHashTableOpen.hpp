#pragma once

#include "HashTableOpen.hpp"
#include "hashing.hpp"
#include <string>

template<typename Val>
class StringHashTableOpen: public HashTableOpen<std::string, Val> {
protected:
    // calls the appropriate hashing code
    int hash(const std::string&) const override;

    // parameter (which must not be changed) for the string hashing function
    int foldNum;

public:
    // default constructor
    StringHashTableOpen(int maxSize = 100, int foldNum = 2);
};

template<typename Val>
StringHashTableOpen<Val>::StringHashTableOpen(int maxSize, int foldNum) :
        HashTableOpen<std::string, Val>(maxSize) {
    this->foldNum = foldNum;
}

template<typename Val>
int StringHashTableOpen<Val>::hash(const std::string &k) const {
    return hashString(k, foldNum);
}
