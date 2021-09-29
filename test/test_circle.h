#pragma once

#include <algorithm>
#include <vector>
#include "../src/circle.h"

// TEST(CaseCircle, Creation) {
//     Square s(10.0);
//     ASSERT_NEAR(10, s.sideLength(), 0.001);
// }

TEST(CaseCircle, Area) {
    Circle s(10.0);
    ASSERT_NEAR(314.159, s.area(), 0.001);
}

// lambda
TEST(CaseCircle, SortIncreasing) {
    vector<Circle> circles;
    circles.push_back(Circle(10));
    circles.push_back(Circle(100));

    std::sort(circles.begin(), circles.end(), [](Circle s1, Circle s2) {
        return circles.area() < circles.area();
    });
    ASSERT_NEAR(314.159, circles[0].area(),0.0001);
    ASSERT_NEAR(31415.9, circles[1].area(),0.0001);
}