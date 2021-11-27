#pragma once
#include "../src/two_dimensional_vector.h"

#define ACCURACY 0.001

class CaseTwoDimensionalVector : public ::testing::Test
{
protected:
    void SetUp() override
    {
        vector2_3_4 = new TwoDimensionalVector(3.0, 4.0);
        vector2_5_12 = new TwoDimensionalVector(5.0, 12.0);
    }

    void TearDown() override
    {
        delete vector2_3_4;
        delete vector2_5_12;
    }

    TwoDimensionalVector *vector2_3_4;
    TwoDimensionalVector *vector2_5_12;
};

TEST_F(CaseTwoDimensionalVector, CreateSuccessfully)
{
    ASSERT_NO_THROW(TwoDimensionalVector vector2_3_4(3.0, 4.0));
}

TEST_F(CaseTwoDimensionalVector, Vector)
{
    ASSERT_NEAR(3.0, vector2_3_4->x(), ACCURACY);
    ASSERT_NEAR(4.0, vector2_3_4->y(), ACCURACY);
}

TEST_F(CaseTwoDimensionalVector, Length)
{
    ASSERT_NEAR(5.0, vector2_3_4->length(), ACCURACY);
}

TEST_F(CaseTwoDimensionalVector, Info)
{
    const std::string expected = "[3.00,4.00]";
    ASSERT_EQ(expected, vector2_3_4->info());
}

TEST_F(CaseTwoDimensionalVector, InfoShouldOnlyShouldTwoDecimal)
{
    TwoDimensionalVector v2(1.234, 1.234);
    const std::string expected = "[1.23,1.23]";

    ASSERT_EQ(expected, v2.info());
}

TEST_F(CaseTwoDimensionalVector, Subtract)
{
    TwoDimensionalVector vec_sub = vector2_5_12->subtract(*vector2_3_4);
    ASSERT_NEAR(2.0, vec_sub.x(), ACCURACY);
    ASSERT_NEAR(8.0, vec_sub.y(), ACCURACY);
}

TEST_F(CaseTwoDimensionalVector, Dot)
{
    ASSERT_NEAR(63.0, vector2_3_4->dot(*vector2_5_12), ACCURACY);
}

TEST_F(CaseTwoDimensionalVector, DotWithVerticalVectorShouldBeZero)
{
    TwoDimensionalVector vec_vertical(-4, 3);
    ASSERT_NEAR(0, vector2_3_4->dot(vec_vertical), ACCURACY);
}

TEST_F(CaseTwoDimensionalVector, Cross)
{
    ASSERT_NEAR(16.0, vector2_3_4->cross(*vector2_5_12), ACCURACY);
}

TEST_F(CaseTwoDimensionalVector, CrossWithParallelShouldBeZero)
{
    TwoDimensionalVector vec_parallel(6, 8);
    ASSERT_NEAR(0, vector2_3_4->cross(vec_parallel), ACCURACY);
}

TEST_F(CaseTwoDimensionalVector, EuclideanDistance)
{
    // vector2 (3, 4) with vector(0, 0) distance should be 5
    TwoDimensionalVector vec_zero;
    ASSERT_NEAR(5.0, vector2_3_4->euclideanDistance(vec_zero), ACCURACY);
}