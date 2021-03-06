#include "gtest/gtest.h"
#include "TMatrix.h"

TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    ASSERT_NO_THROW(TMatrix<int> m(1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
    TMatrix<int> m(5);

    ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int> m1(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m1[i][k] = 0;
        }
    }
    m1[1][1] = 4;
    TMatrix<int> m2(m1);
    EXPECT_EQ(m1, m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> m1(5);
     for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m1[i][k] = 0;
        }
    }
    m1[1][1] = 4;
    TMatrix<int> m2(m1);
    m2[1][1] = 3;
    EXPECT_EQ(m1 == m2, false);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> m(5);
    EXPECT_EQ(m.GetSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> m(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m[i][k] = 0;
        }
    }
    m[1][1] = 3;
    EXPECT_EQ(m[1][1], 3);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> m(5);
    ASSERT_ANY_THROW(m[-1][-1] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> m(5);
    ASSERT_ANY_THROW(m[3][7] = 1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> m(5);
    ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> m1(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m1[i][k] = 0;
        }
    }
    m1[1][1] = 30;
    TMatrix<int> m2(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m2[i][k] = 0;
        }
    }
    m2 = m1;
    EXPECT_EQ(m1, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> m1(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m1[i][k] = 0;
        }
    }
    m1[1][1] = 3;
    TMatrix<int> m2(9);
    for (int i = 0; i < 9; i++)
    {
        for (int k = i; k < 9; k++)
        {
            m2[i][k] = 0;
        }
    }
    m2 = m1;
    EXPECT_EQ(5, m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> m1(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m1[i][k] = 0;
        }
    }
    m1[1][1] = 3;
    TMatrix<int> m2(9);
    for (int i = 0; i < 9; i++)
    {
        for (int k = i; k < 9; k++)
        {
            m2[i][k] = 0;
        }
    }
    m2 = m1;
    EXPECT_EQ(m1, m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> m1(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m1[i][k] = 0;
        }
    }
    m1[1][1] = 3;
    TMatrix<int> m2(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m2[i][k] = 0;
        }
    }
    m2[1][1] = 3;
    EXPECT_EQ(true, m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> m(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m[i][k] = 0;
        }
    }
    m[1][1] = 3;
    EXPECT_EQ(true, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> m1(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m1[i][k] = 0;
        }
    }
    m1[1][1] = 3;
    TMatrix<int> m2(6);
    for (int i = 0; i < 6; i++)
    {
        for (int k = i; k < 6; k++)
        {
            m2[i][k] = 0;
        }
    }
    m2[1][1] = 3;
    EXPECT_EQ(true, m1 != m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> m1(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m1[i][k] = 0;
        }
    }
    m1[1][1] = 3;
    TMatrix<int> m2(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m2[i][k] = 0;
        }
    }
    m2[1][1] = 3;
    TMatrix<int> m3(m1 + m2);
    EXPECT_EQ(m3[1][1], 6);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> m1(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m1[i][k] = 0;
        }
    }
    TMatrix<int> m2(6);
    for (int i = 0; i < 6; i++)
    {
        for (int k = i; k < 6; k++)
        {
            m2[i][k] = 0;
        }
    }
    ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> m1(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m1[i][k] = 0;
        }
    }
    m1[1][1] = 3;
    TMatrix<int> m2(5);
    for (int i = 0; i < 5; i++)
    {
        for (int k = i; k < 5; k++)
        {
            m2[i][k] = 0;
        }
    }
    m2[1][1] = 3;
    TMatrix<int> m3(m1 - m2);
    EXPECT_EQ(m3[1][1], 0);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    int s = 7;
    TMatrix<int> m1(s);
    for (int i = 0; i < s; i++)
    {
        for (int k = i; k < s; k++)
        {
            m1[i][k] = 0;
        }
    }
    int s2 = 8;
    TMatrix<int> m2(8);
    for (int i = 0; i < s2; i++)
    {
        for (int k = i; k < s2; k++)
        {
            m2[i][k] = 0;
        }
    }
    ASSERT_ANY_THROW(m1 - m2);
}