#pragma once
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/shape.h"

#define ACCURACY 0.001

class CaseShape : public ::testing::Test
{
protected:
    void SetUp() override
    {
        r3_4 = new Rectangle(3.0, 4.0);
        c10 = new Circle(10.0);
        t3_4 = new Triangle(TwoDimensionalVector(3, 0), TwoDimensionalVector(0, 4));
    }

    void TearDown() override
    {
        delete r3_4;
        delete c10;
    }

    Shape *r3_4;
    Shape *c10;
    Shape *t3_4;
};

TEST_F(CaseShape, Area)
{
    ASSERT_NEAR(12.0, r3_4->area(), ACCURACY);
    ASSERT_NEAR(314.159, c10->area(), ACCURACY);
    ASSERT_NEAR(6.0, t3_4->area(), ACCURACY);
}

TEST_F(CaseShape, Perimeter)
{
    ASSERT_NEAR(14.0, r3_4->perimeter(), ACCURACY);
    ASSERT_NEAR(62.8318, c10->perimeter(), ACCURACY);
    ASSERT_NEAR(12.0, t3_4->perimeter(), ACCURACY);
}

TEST_F(CaseShape, Info)
{
    std::string rectangle = "Rectangle (3.00 4.00)";
    std::string circle    = "Circle (10.00)";
    std::string triangle  = "Triangle ([3.00,0.00] [0.00,4.00])";

    ASSERT_EQ(rectangle, r3_4->info());
    ASSERT_EQ(circle, c10->info());
    ASSERT_EQ(triangle, t3_4->info());
}
