#include "gtest/gtest.h"
#include "TMatrix.h"

using namespace std;

int main(int argc, char **argv)
{
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
    TMatrix<int> matrix(5);
    std::cout << matrix;
}