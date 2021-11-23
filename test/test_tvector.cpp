#include "gtest/gtest.h"
#include "TMatrix.h"

TEST(TVector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(TVector<int> v(5));
}

//Too large index doesn't exist
//TEST(TVector, cant_create_too_large_vector)
//{
//    ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
//}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
    ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
    const TVector<int> v(10);

    ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
    const TVector<int> v(10);
    const TVector<int> v1(v);
    EXPECT_EQ(v == v1, true);
}

//What is it?
//TEST(TVector, copied_vector_has_its_own_memory)
//{
//    ADD_FAILURE();
//}

TEST(TVector, can_get_size)
{
    int s = 4;
    TVector<int> v(s);

    EXPECT_EQ(s, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
    int s = 4;
    int si = 2;
    TVector<int> v(s, si);

    EXPECT_EQ(si, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
    TVector<int> v(4);
    v[0] = 4;

    EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
    TVector<int> v;
    ASSERT_ANY_THROW(v[-3]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    int s = 13;
    TVector<int> v(s);
    ASSERT_ANY_THROW(v[s]);
}

TEST(TVector, can_assign_vector_to_itself)
{
    int s = 13;
    TVector<int> v(s);

    ASSERT_NO_THROW(v = TVector<int>(v));
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    int s = 13;
    TVector<int> v(s);
    TVector<int> v1(s);
    v[0] = 15;
    ASSERT_NO_THROW(v1 = v);
}

TEST(TVector, assign_operator_change_vector_size)
{
    int s1 = 13;
    int s2 = 19;
    TVector<int> v1(s1);
    TVector<int> v2(s2);
    v1[0] = 15;
    v2 = v1;
    EXPECT_EQ(13, v2.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    int s1 = 13;
    int s2 = 19;
    TVector<int> v1(s1);
    TVector<int> v2(s2);
    v1[0] = 15;
    ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    int s1 = 13;
    int s2 = 19;
    TVector<int> v1(s1);
    TVector<int> v2(s2);
    v1 = v2;
    v1[0] = 15;
    v2[0] = 15;
    EXPECT_EQ(v1 == v2, true);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    int s1 = 13;
    TVector<int> v1(s1);
    EXPECT_EQ(v1 == v1, true);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    int s1 = 13;
    int s2 = 19;
    TVector<int> v1(s1);
    TVector<int> v2(s2);
    EXPECT_EQ(v1 == v2, false);
}

TEST(TVector, can_add_scalar_to_vector)
{
    int s1 = 13;
    int scal_val = 5;
    TVector<int> v1(s1);

    ASSERT_NO_THROW(v1 = v1 + scal_val);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    int s1 = 13;
    int scal_val = 5;
    TVector<int> v1(s1);

    ASSERT_NO_THROW(v1 = v1 - scal_val);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    int s1 = 13;
    int scal_val = 5;
    TVector<int> v1(s1);

    ASSERT_NO_THROW(v1 = v1 *  scal_val);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    int s1 = 13;
    int sc1 = 12, sc2 = 17;
    TVector<int> v1(s1);
    TVector<int> v2(s1);
    v1 = v1 + sc1;
    v2 = v2 + sc2;
    v1 = v1 + v2;

    EXPECT_EQ(v1[3], sc1 + sc2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    int s1 = 13;
    int s2 = 19;
    TVector<int> v1(s1);
    TVector<int> v2(s2);

    ASSERT_ANY_THROW(v1 = v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    int s1 = 13;
    int sc1 = 12, sc2 = 17;
    TVector<int> v1(s1);
    TVector<int> v2(s1);
    v1 = v1 + sc1;
    v2 = v2 + sc2;
    v1 = v1 - v2;

    EXPECT_EQ(v1[3], sc1 - sc2);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    int s1 = 13;
    int s2 = 19;
    TVector<int> v1(s1);
    TVector<int> v2(s2);

    ASSERT_ANY_THROW(v1 = v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    int s1 = 13;
    int sc1 = 12, sc2 = 17;
    TVector<int> v1(s1);
    TVector<int> v2(s1);
    v1 = v1 + sc1;
    v2 = v2 + sc2;
    int res = v1 * v2;

    int check = 0;
    for(int i =  0; i < v1.GetSize(); i++)
    {
        check += v1[i] * v2[i];
    }
    EXPECT_EQ(res, check);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    int s1 = 13;
    int s2 = 19;
    TVector<int> v1(s1);
    TVector<int> v2(s2);
    int res;

    ASSERT_ANY_THROW(res = v1 * v2);
}