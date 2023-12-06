#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../kdtree/KDTree.hpp"
#include "../reader/Reader.hpp"

void testPointsOctree(const std::string &filename, KDTree &kdtree)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string token;
        double x, y;

        if (std::getline(ss, token, ','))
            x = std::stod(token);
        if (std::getline(ss, token, '\n'))
            y = std::stod(token);

        EXPECT_TRUE(kdtree.search(Point(x, y))) << "Point (" << x << ", " << y << ") not found in the Octree.";
    }
    file.close();
}

TEST(KDTreeTest, PointsFromCSVTest_1)
{
    KDTree kdtree(2);
    Reader csv;
    kdtree = csv.readAndConvert(1);
    std::string filename = "../Resources/1000.csv";
    testPointsOctree(filename, kdtree);
}

TEST(KDTreeTest, PointsFromCSVTest_2)
{
    KDTree kdtree(2);
    Reader csv;
    kdtree = csv.readAndConvert(2);
    std::string filename = "../Resources/10000.csv";
    testPointsOctree(filename, kdtree);
}

TEST(KDTreeTest, PointsFromCSVTest_3)
{
    KDTree kdtree(2);
    Reader csv;
    kdtree = csv.readAndConvert(3);
    std::string filename = "../Resources/20000.csv";
    testPointsOctree(filename, kdtree);
}