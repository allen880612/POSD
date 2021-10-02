#pragma once
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "../src/rectangle.h"

#define EXCEPTION_MSG std::string("Rectangle created by positive double length and width.")

TEST(CaseRectangle, Creation)
{
    Rectangle r4_5(4.0, 5.0);
    ASSERT_NEAR(20, r4_5.area(), 0.001);
    ASSERT_NEAR(18, r4_5.perimeter(), 0.001);
}

TEST(CaseRectangle, Info)
{
    Rectangle r4_5(4.32, 5.67);
    std::string expected = "Rectangle (4.32, 5.67)";

    ASSERT_EQ(expected, r4_5.info());
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
        EXPECT_EQ(EXCEPTION_MSG, e.what());
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
        EXPECT_EQ(EXCEPTION_MSG, e.what());
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
        EXPECT_EQ(EXCEPTION_MSG, e.what());
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
        EXPECT_EQ(EXCEPTION_MSG, e.what());
    }
}
