#pragma once
#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <iostream>

#include "../src/circle.h"

TEST(CaseCircle, Area) {
    Circle s(10.0);
    ASSERT_NEAR(314.159, s.area(), 0.001);
}

// lambda
TEST(CaseCircle, SortIncreasing) {
    std::vector<Circle*> circles;
    circles.push_back(new Circle(10.0));
    circles.push_back(new Circle(100.0));

    std::sort(circles.begin(), circles.end(), [](Circle* c1, Circle* c2) {
        return c1->area() < c2->area();
    });

    ASSERT_NEAR(314.159, circles[0]->area(), 0.1);
    ASSERT_NEAR(31415.9, circles[1]->area(), 0.1);
}