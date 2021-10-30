#pragma once
#include <gtest/gtest.h>
#include "../src/triangle.h"

#define TRIANGLE_EXCEPTION_MSG std::string("Triangle created by two non-parallel two dimensional _vectors.")
#define ACCURACY 0.001


class CaseTriangle : public ::testing::Test
{
protected:
    void SetUp() override
    {
        vector2_3_0 = new TwoDimensionalVector(3.0, 0.0);
        vector2_0_4 = new TwoDimensionalVector(0.0, 4.0);
        vector2_3_4 = new TwoDimensionalVector(3.0, 4.0);
        vector2_n3_n4 = new TwoDimensionalVector(-3.0, -4.0);
        t34 = new Triangle(*vector2_3_0, *vector2_0_4);
    }

    void TearDown() override
    {
        delete vector2_3_0;
        delete vector2_0_4;
        delete vector2_3_4;
        delete vector2_n3_n4;
        delete t34;
    }

    TwoDimensionalVector *vector2_3_0;
    TwoDimensionalVector *vector2_0_4;
    TwoDimensionalVector *vector2_3_4;
    TwoDimensionalVector *vector2_n3_n4;

    Triangle* t34;
};

TEST_F(CaseTriangle, CreateSuccessfully)
{
    ASSERT_NO_THROW(Triangle t(*vector2_3_0, *vector2_0_4));
}

TEST_F(CaseTriangle, CreateWithParallelShouldThrowException)
{
    TwoDimensionalVector parallel_vec(6.0, 8.0);
    ASSERT_THROW(Triangle t(*vector2_3_4, parallel_vec), std::invalid_argument);    
}

TEST_F(CaseTriangle, CreateWithParallelShouldThrowExceptionWithErrorMessage)
{
    TwoDimensionalVector parallel_vec(6.0, 8.0);
    try
    {
        Triangle t(*vector2_3_4, parallel_vec);
        FAIL();
    }
    catch(std::invalid_argument const &e)
    {
        ASSERT_EQ(TRIANGLE_EXCEPTION_MSG, e.what());
    }
}

TEST_F(CaseTriangle, Info)
{
    const std::string expected = "Triangle ([3.00,0.00] [0.00,4.00])";
    ASSERT_EQ(expected, t34->info());
}

TEST_F(CaseTriangle, Perimeter)
{
    ASSERT_NEAR(12.0, t34->perimeter(), ACCURACY);
}

TEST_F(CaseTriangle, Area)
{
    ASSERT_NEAR(6.0, t34->area(), ACCURACY);
}