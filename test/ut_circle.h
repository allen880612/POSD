#pragma once
#include "../src/circle.h"

#define CIRCLE_EXCEPTION_MSG std::string("Circle created by positive double radius.")
#define ACCURACY 0.001

TEST(CaseCircle, CreateSuccessfully) {
    ASSERT_NO_THROW(Circle s(10.0));
}

TEST(CaseCircle, CreateWWithNegativeRadiusShouldThrowException) {
    try
    {
        Circle c(-1);
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ(CIRCLE_EXCEPTION_MSG, e);
    }
}

TEST(CaseCircle, CreateWWithZeroRadiusShouldThrowException) {
    try
    {
        Circle c(0);
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ(CIRCLE_EXCEPTION_MSG, e);
    }
}

TEST(CaseCircle, Area) {
    Circle c(10.0);
    ASSERT_NEAR(314.159, c.area(), ACCURACY);
}

TEST(CaseCircle, Perimeter) {
    Circle c(10.0);
    ASSERT_NEAR(62.8318, c.perimeter(), ACCURACY);
}

TEST(CaseCircle, Info) {
    Circle c(10.0);
    const std::string expected = "Circle (10.00)";
    ASSERT_EQ(expected, c.info());
}

TEST(CaseCircle, InfoShouldOnlyShowTwoDecimal) {
    Circle c(10.123);
    const std::string expected = "Circle (10.12)";
    ASSERT_EQ(expected, c.info());
}