#ifndef READER_HPP
#define READER_HPP

#include "../KDTree/kdtree.hpp"
#include "../Direct/direct.hpp"
class Reader
{
public:
    KDTree readAndConvert(int fileNumber);
    Direct readAndConvertDirect(int fileNumber);
};

#endif // READER_HPP