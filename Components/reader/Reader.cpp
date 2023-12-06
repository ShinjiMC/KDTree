#include <iostream>
#include <fstream>
#include <sstream>
#include "Reader.hpp"

KDTree Reader::readAndConvert(int fileNumber)
{
    std::string filename = "../Resources/";
    if (fileNumber == 1)
        filename += "1000.csv";
    else if (fileNumber == 2)
        filename += "10000.csv";
    else if (fileNumber == 3)
        filename += "100000.csv";
    else
        filename += "1000.csv";
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file " << filename << std::endl;
        return KDTree(2);
    }
    KDTree kdtree(2);
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string token;
        double x, y;
        if (std::getline(ss, token, ','))
            x = std::stoi(token);
        if (std::getline(ss, token, '\n'))
            y = std::stoi(token);
        kdtree.insert(Point(x, y));
    }
    file.close();
    return kdtree;
}