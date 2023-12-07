#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../KDTree/kdtree.hpp"
#include "../Reader/reader.hpp"
#include "../Direct/direct.hpp"

class KDTreeTest : public ::testing::Test
{
protected:
    KDTree kdtree;
    Reader csv;

    void SetUp() override
    {
        kdtree = KDTree(3);
    }

    void TearDown() override
    {
        kdtree.clear();
    }
};

class DirectTest : public ::testing::Test
{
protected:
    Direct direct;
    Reader csv;

    void SetUp() override
    {
        direct = Direct();
    }

    void TearDown() override
    {
        direct.clear();
    }
};

void testPointsKDTree(const std::string &filename, KDTree &kdtree)
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
        double x, y, z;

        if (std::getline(ss, token, ','))
            x = std::stod(token);
        if (std::getline(ss, token, ','))
            y = std::stod(token);
        if (std::getline(ss, token, '\n'))
            z = std::stod(token);

        EXPECT_TRUE(kdtree.search(Vec3D(x, y, z))) << "Point (" << x << ", " << y << ", " << z << ") not found in the KDTree.";
    }
    file.close();
}

void testPointsDirect(const std::string &filename, Direct &direct)
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
        double x, y, z;

        if (std::getline(ss, token, ','))
            x = std::stod(token);
        if (std::getline(ss, token, ','))
            y = std::stod(token);
        if (std::getline(ss, token, '\n'))
            z = std::stod(token);

        EXPECT_TRUE(direct.search(Vec3D(x, y, z))) << "Point (" << x << ", " << y << ", " << z << ") not found in the KDTree.";
    }
    file.close();
}

// KDTree Test
TEST_F(KDTreeTest, InsertionPointsFromCSVTest_1)
{
    kdtree = csv.readAndConvert(1);
}

TEST_F(KDTreeTest, InsertionPointsFromCSVTest_2)
{
    kdtree = csv.readAndConvert(2);
}

TEST_F(KDTreeTest, InsertionPointsFromCSVTest_3)
{
    kdtree = csv.readAndConvert(3);
}

// Direct Test
TEST_F(DirectTest, InsertionPointsFromCSVTest_1)
{
    direct = csv.readAndConvertDirect(1);
}

TEST_F(DirectTest, InsertionPointsFromCSVTest_2)
{
    direct = csv.readAndConvertDirect(2);
}

TEST_F(DirectTest, InsertionPointsFromCSVTest_3)
{
    direct = csv.readAndConvertDirect(3);
}

// KDTree Test
TEST_F(KDTreeTest, InsertionandSearchPointsFromCSVTest_1)
{
    kdtree = csv.readAndConvert(1);
    std::string filename = "../Resources/1000.csv";
    testPointsKDTree(filename, kdtree);
}

TEST_F(KDTreeTest, InsertionandSearchPointsFromCSVTest_2)
{
    kdtree = csv.readAndConvert(2);
    std::string filename = "../Resources/10000.csv";
    testPointsKDTree(filename, kdtree);
}

TEST_F(KDTreeTest, InsertionandSearchPointsFromCSVTest_3)
{
    kdtree = csv.readAndConvert(3);
    std::string filename = "../Resources/20000.csv";
    testPointsKDTree(filename, kdtree);
}

// Direct Test
TEST_F(DirectTest, InsertionandSearchPointsFromCSVTest_1)
{
    direct = csv.readAndConvertDirect(1);
    std::string filename = "../Resources/1000.csv";
    testPointsDirect(filename, direct);
}

TEST_F(DirectTest, InsertionandSearchPointsFromCSVTest_2)
{
    direct = csv.readAndConvertDirect(2);
    std::string filename = "../Resources/10000.csv";
    testPointsDirect(filename, direct);
}

TEST_F(DirectTest, InsertionandSearchPointsFromCSVTest_3)
{
    direct = csv.readAndConvertDirect(3);
    std::string filename = "../Resources/20000.csv";
    testPointsDirect(filename, direct);
}