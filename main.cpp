#include "Components/Reader/Reader.hpp"
#include "Components/Tester/tester.cpp"
#include <iostream>
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}