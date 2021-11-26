#include "gtest/gtest.h"
#include "TMatrix.h"

using namespace std;

int main(int argc, char **argv)
{
    TMatrix<int> matrix(5);
    matrix.input();
    matrix.print();
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
}