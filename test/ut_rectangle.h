#pragma once
#include <gtest/gtest.h>
#include "../src/rectangle.h"

#define RECTANGLE_EXCEPTION_MSG std::string("Rectangle created by positive double length and width.")
#define ACCURACY 0.001

class CaseRectangle : public ::testing::Test
{
protected:
    void SetUp() override
    {
        r4_5 = new Rectangle(4.0, 5.0);
    }

    void TearDown() override
    {
        delete r4_5;
    }

    Rectangle* r4_5;
};

TEST_F(CaseRectangle, CreateSuccessfully)
{
    ASSERT_NO_THROW(Rectangle r4_5(4.0, 5.0));
}

TEST_F(CaseRectangle, CreateWithNegativeLength)
{
    ASSERT_THROW(Rectangle r_negative_length(-4.0, 5.0), std::invalid_argument);
}

TEST_F(CaseRectangle, CreateWithNegativeWidth)
{
    ASSERT_THROW(Rectangle r_negative_width(4.0, -5.0), std::invalid_argument);
}

TEST_F(CaseRectangle, CreateWithZeroLength)
{
    ASSERT_THROW(Rectangle r0_5(0, 5.0), std::invalid_argument);
}

TEST_F(CaseRectangle, CreateWithZeroWidth)
{
    ASSERT_THROW(Rectangle r4_0(4.0, 0), std::invalid_argument);
}

TEST_F(CaseRectangle, Info)
{
    Rectangle r_decimal(4.32, 5.67);
    std::string expected = "Rectangle (4.32 5.67)";

    ASSERT_EQ(expected, r_decimal.info());
}

TEST_F(CaseRectangle, InfoShouldOnlyShowTwoDecimal)
{
    Rectangle r_decimal(4.123, 5.123);
    std::string expected = "Rectangle (4.12 5.12)";

    ASSERT_EQ(expected, r_decimal.info());
}

TEST_F(CaseRectangle, InfoShouldShowTwoDecimal)
{
    Rectangle r_decimal(4.1, 5.1);
    std::string expected = "Rectangle (4.10 5.10)";

    ASSERT_EQ(expected, r_decimal.info());
}

TEST_F(CaseRectangle, Area)
{
    ASSERT_NEAR(20.0, r4_5->area(), ACCURACY);
}

TEST_F(CaseRectangle, Perimeter)
{
    ASSERT_NEAR(18.0, r4_5->perimeter(), ACCURACY);
}

TEST_F(CaseRectangle, AddShouldThrowException) {
    ASSERT_ANY_THROW(r4_5->addShape(nullptr));
}

TEST_F(CaseRectangle, DeleteShouldThrowException) {
    ASSERT_ANY_THROW(r4_5->deleteShape(nullptr));
}

TEST_F(CaseRectangle, IsDoneOfCreateIteratorShouldBeTrue) {
    ASSERT_TRUE(r4_5->createIterator()->isDone());
}