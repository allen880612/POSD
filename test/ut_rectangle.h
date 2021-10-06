#pragma once
#include "../src/rectangle.h"

#define RECTANGLE_EXCEPTION_MSG std::string("Rectangle created by positive double length and width.")
#define ACCURACY 0.001

TEST(CaseRectangle, CreateSuccessfully)
{
    ASSERT_NO_THROW(Rectangle r4_5(4.0, 5.0));
}

TEST(CaseRectangle, CreateWithNegativeLength)
{
    try
    {
        Rectangle r_negative_length(-4.0, 5.0);
        FAIL();
    }
    catch (std::invalid_argument const &e)
    {
        ASSERT_EQ(RECTANGLE_EXCEPTION_MSG, e.what());
    }
}

TEST(CaseRectangle, CreateWithNegativeWidth)
{
    try
    {
        Rectangle r_negative_width(4.0, -5.0);
        FAIL();
    }
    catch (std::invalid_argument const &e)
    {
        ASSERT_EQ(RECTANGLE_EXCEPTION_MSG, e.what());
    }
}

TEST(CaseRectangle, CreateWithZeroLength)
{
    try
    {
        Rectangle r0_5(0, 5.0);
        FAIL();
    }
    catch (std::invalid_argument const &e)
    {
        ASSERT_EQ(RECTANGLE_EXCEPTION_MSG, e.what());
    }
}

TEST(CaseRectangle, CreateWithZeroWidth)
{
    try
    {
        Rectangle r4_0(4.0, 0);
        FAIL();
    }
    catch (std::invalid_argument const &e)
    {
        ASSERT_EQ(RECTANGLE_EXCEPTION_MSG, e.what());
    }

    
}

TEST(CaseRectangle, Info)
{
    Rectangle r_decimal(4.32, 5.67);
    std::string expected = "Rectangle (4.32 5.67)";

    ASSERT_EQ(expected, r_decimal.info());
}

TEST(CaseRectangle, InfoShouldOnlyShowTwoDecimal)
{
    Rectangle r_decimal(4.123, 5.123);
    std::string expected = "Rectangle (4.12 5.12)";

    ASSERT_EQ(expected, r_decimal.info());
}

TEST(CaseRectangle, InfoShouldShowTwoDecimal)
{
    Rectangle r_decimal(4.1, 5.1);
    std::string expected = "Rectangle (4.10 5.10)";

    ASSERT_EQ(expected, r_decimal.info());
}

TEST(CaseRectangle, Area)
{
    Rectangle r4_5(4.0, 5.0);

    ASSERT_NEAR(20.0, r4_5.area(), ACCURACY);
}

TEST(CaseRectangle, Perimeter)
{
    Rectangle r4_5(4.0, 5.0);

    ASSERT_NEAR(18.0, r4_5.perimeter(), ACCURACY);
}
