#ifndef READER_HPP
#define READER_HPP

#include "../kdtree/KDTree.hpp"
class Reader
{
public:
    KDTree readAndConvert(int fileNumber);
};

#endif // READER_HPP