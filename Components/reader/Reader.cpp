#include <iostream>
#include <fstream>
#include <sstream>
#include "reader.hpp"

KDTree Reader::readAndConvert(int fileNumber)
{
    std::string filename = "../Resources/";
    if (fileNumber == 1)
        filename += "1000.csv";
    else if (fileNumber == 2)
        filename += "10000.csv";
    else if (fileNumber == 3)
        filename += "20000.csv";
    else
        filename += "1000.csv";
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file " << filename << std::endl;
        return KDTree();
    }
    KDTree kdtree(2);
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string token;
        double x, y, z;
        if (std::getline(ss, token, ','))
            x = std::stoi(token);
        if (std::getline(ss, token, ','))
            y = std::stoi(token);
        if (std::getline(ss, token, '\n'))
            z = std::stoi(token);
        kdtree.insert(Vec3D(x, y, z));
    }
    file.close();
    return kdtree;
}

Direct Reader::readAndConvertDirect(int fileNumber)
{
    std::string filename = "../Resources/";
    if (fileNumber == 1)
        filename += "1000.csv";
    else if (fileNumber == 2)
        filename += "10000.csv";
    else if (fileNumber == 3)
        filename += "20000.csv";
    else
        filename += "1000.csv";
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file " << filename << std::endl;
        return Direct();
    }
    Direct direct;
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string token;
        double x, y, z;
        if (std::getline(ss, token, ','))
            x = std::stoi(token);
        if (std::getline(ss, token, ','))
            y = std::stoi(token);
        if (std::getline(ss, token, '\n'))
            z = std::stoi(token);
        direct.insert(Vec3D(x, y, z));
    }
    file.close();
    return direct;
}