#include "gtest/gtest.h"
#include "TMatrix.h"

using namespace std;

int main(int argc, char **argv)
{
    TMatrix<int> matrix(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            matrix[i][k] = k + i;
        }
    }
    cout << matrix;
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();

}