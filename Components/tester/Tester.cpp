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

void testPointsKNN_KDTREE(const std::string &filename, KDTree &kdtree, int cantPoints)
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
        EXPECT_NO_THROW({ kdtree.KNN(Vec3D(x, y, z), cantPoints); }) << "Error occurred while executing KNN for point (" << x << ", " << y << ", " << z << ").";
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

void testPointsKNN_Direct(const std::string &filename, Direct &direct, int cantPoints)
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
        EXPECT_NO_THROW({ direct.KNN(Vec3D(x, y, z), cantPoints); }) << "Error occurred while executing KNN for point (" << x << ", " << y << ", " << z << ").";
    }
    file.close();
}

// KDTree Test
TEST_F(KDTreeTest, InsertionPointsFromCSVTest_1)
{
    try
    {
        kdtree = csv.readAndConvert(1);
    }
    catch (const std::runtime_error &e)
    {
        FAIL() << "Error al leer e insertar puntos desde el archivo CSV: " << e.what();
    }
}

TEST_F(KDTreeTest, InsertionPointsFromCSVTest_2)
{
    try
    {
        kdtree = csv.readAndConvert(2);
    }
    catch (const std::runtime_error &e)
    {
        FAIL() << "Error al leer e insertar puntos desde el archivo CSV: " << e.what();
    }
}

TEST_F(KDTreeTest, InsertionPointsFromCSVTest_3)
{
    try
    {
        kdtree = csv.readAndConvert(3);
    }
    catch (const std::runtime_error &e)
    {
        FAIL() << "Error al leer e insertar puntos desde el archivo CSV: " << e.what();
    }
}

// Direct Test
TEST_F(DirectTest, InsertionPointsFromCSVTest_1)
{
    try
    {
        direct = csv.readAndConvertDirect(1);
    }
    catch (const std::runtime_error &e)
    {
        FAIL() << "Error al leer e insertar puntos desde el archivo CSV: " << e.what();
    }
}

TEST_F(DirectTest, InsertionPointsFromCSVTest_2)
{
    try
    {
        direct = csv.readAndConvertDirect(2);
    }
    catch (const std::runtime_error &e)
    {
        FAIL() << "Error al leer e insertar puntos desde el archivo CSV: " << e.what();
    }
}

TEST_F(DirectTest, InsertionPointsFromCSVTest_3)
{
    try
    {
        direct = csv.readAndConvertDirect(3);
    }
    catch (const std::runtime_error &e)
    {
        FAIL() << "Error al leer e insertar puntos desde el archivo CSV: " << e.what();
    }
}

// KDTree Test
TEST_F(KDTreeTest, Insertion_Search_PointsFromCSVTest_1)
{
    kdtree = csv.readAndConvert(1);
    std::string filename = "../Resources/1000.csv";
    testPointsKDTree(filename, kdtree);
}

TEST_F(KDTreeTest, Insertion_Search_PointsFromCSVTest_2)
{
    kdtree = csv.readAndConvert(2);
    std::string filename = "../Resources/10000.csv";
    testPointsKDTree(filename, kdtree);
}

TEST_F(KDTreeTest, Insertion_Search_PointsFromCSVTest_3)
{
    kdtree = csv.readAndConvert(3);
    std::string filename = "../Resources/20000.csv";
    testPointsKDTree(filename, kdtree);
}

// Direct Test
TEST_F(DirectTest, Insertion_Search_PointsFromCSVTest_1)
{
    direct = csv.readAndConvertDirect(1);
    std::string filename = "../Resources/1000.csv";
    testPointsDirect(filename, direct);
}

TEST_F(DirectTest, Insertion_Search_PointsFromCSVTest_2)
{
    direct = csv.readAndConvertDirect(2);
    std::string filename = "../Resources/10000.csv";
    testPointsDirect(filename, direct);
}

TEST_F(DirectTest, Insertion_Search_PointsFromCSVTest_3)
{
    direct = csv.readAndConvertDirect(3);
    std::string filename = "../Resources/20000.csv";
    testPointsDirect(filename, direct);
}

// KDTree Test
TEST_F(KDTreeTest, Insertion_KNN_1_PointsFromCSVTest_1)
{
    kdtree = csv.readAndConvert(1);
    std::string filename = "../Resources/1000.csv";
    testPointsKNN_KDTREE(filename, kdtree, 1);
}

TEST_F(KDTreeTest, Insertion_KNN_1_PointsFromCSVTest_2)
{
    kdtree = csv.readAndConvert(2);
    std::string filename = "../Resources/10000.csv";
    testPointsKNN_KDTREE(filename, kdtree, 1);
}

TEST_F(KDTreeTest, Insertion_KNN_1_PointsFromCSVTest_3)
{
    kdtree = csv.readAndConvert(3);
    std::string filename = "../Resources/20000.csv";
    testPointsKNN_KDTREE(filename, kdtree, 1);
}

TEST_F(KDTreeTest, Insertion_KNN_MID_PointsFromCSVTest_1)
{
    kdtree = csv.readAndConvert(1);
    std::string filename = "../Resources/1000.csv";
    testPointsKNN_KDTREE(filename, kdtree, 500);
}

TEST_F(KDTreeTest, Insertion_KNN_MID_PointsFromCSVTest_2)
{
    kdtree = csv.readAndConvert(2);
    std::string filename = "../Resources/10000.csv";
    testPointsKNN_KDTREE(filename, kdtree, 5000);
}

TEST_F(KDTreeTest, Insertion_KNN_MID_PointsFromCSVTest_3)
{
    kdtree = csv.readAndConvert(3);
    std::string filename = "../Resources/20000.csv";
    testPointsKNN_KDTREE(filename, kdtree, 10000);
}

TEST_F(KDTreeTest, Insertion_KNN_MAX_PointsFromCSVTest_1)
{
    kdtree = csv.readAndConvert(1);
    std::string filename = "../Resources/1000.csv";
    testPointsKNN_KDTREE(filename, kdtree, 999);
}

TEST_F(KDTreeTest, Insertion_KNN_MAX_PointsFromCSVTest_2)
{
    kdtree = csv.readAndConvert(2);
    std::string filename = "../Resources/10000.csv";
    testPointsKNN_KDTREE(filename, kdtree, 9999);
}

TEST_F(KDTreeTest, Insertion_KNN_MAX_PointsFromCSVTest_3)
{
    kdtree = csv.readAndConvert(3);
    std::string filename = "../Resources/20000.csv";
    testPointsKNN_KDTREE(filename, kdtree, 19999);
}

// Direct Test
TEST_F(DirectTest, Insertion_KNN_1_PointsFromCSVTest_1)
{
    direct = csv.readAndConvertDirect(1);
    std::string filename = "../Resources/1000.csv";
    testPointsKNN_Direct(filename, direct, 1);
}

TEST_F(DirectTest, Insertion_KNN_1_PointsFromCSVTest_2)
{
    direct = csv.readAndConvertDirect(2);
    std::string filename = "../Resources/10000.csv";
    testPointsKNN_Direct(filename, direct, 1);
}

TEST_F(DirectTest, Insertion_KNN_1_PointsFromCSVTest_3)
{
    direct = csv.readAndConvertDirect(3);
    std::string filename = "../Resources/20000.csv";
    testPointsKNN_Direct(filename, direct, 1);
}

TEST_F(DirectTest, Insertion_KNN_MID_PointsFromCSVTest_1)
{
    direct = csv.readAndConvertDirect(1);
    std::string filename = "../Resources/1000.csv";
    testPointsKNN_Direct(filename, direct, 500);
}

TEST_F(DirectTest, Insertion_KNN_MID_PointsFromCSVTest_2)
{
    direct = csv.readAndConvertDirect(2);
    std::string filename = "../Resources/10000.csv";
    testPointsKNN_Direct(filename, direct, 5000);
}

TEST_F(DirectTest, Insertion_KNN_MID_PointsFromCSVTest_3)
{
    direct = csv.readAndConvertDirect(3);
    std::string filename = "../Resources/20000.csv";
    testPointsKNN_Direct(filename, direct, 10000);
}

TEST_F(DirectTest, Insertion_KNN_MAX_PointsFromCSVTest_1)
{
    direct = csv.readAndConvertDirect(1);
    std::string filename = "../Resources/1000.csv";
    testPointsKNN_Direct(filename, direct, 999);
}

TEST_F(DirectTest, Insertion_KNN_MAX_PointsFromCSVTest_2)
{
    direct = csv.readAndConvertDirect(2);
    std::string filename = "../Resources/10000.csv";
    testPointsKNN_Direct(filename, direct, 9999);
}

TEST_F(DirectTest, Insertion_KNN_MAX_PointsFromCSVTest_3)
{
    direct = csv.readAndConvertDirect(3);
    std::string filename = "../Resources/20000.csv";
    testPointsKNN_Direct(filename, direct, 19999);
}