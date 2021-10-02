#pragma once
// #include <algorithm>
// #include <vector>
#include "../src/circle.h"
#include "../src/shape.h"

// class CaseShape : public ::testing::Test
// {
// protected:
//     void SetUp() override
//     {
//         s10 = new Square(10.0);
//         c10 = new Circle(10.0);
//     }

//     void TearDown() override
//     {
//         delete s10;
//         delete c10;
//     }

//     Shape *s10;
//     Shape *c10;
// };

// TEST_F(CaseShape, CreationShape)
// {
//     ASSERT_NEAR(100, s10->area(), 0.0001);
//     ASSERT_NEAR(40, s10->perimeter(), 0.0001);

//     ASSERT_NEAR(314.15, c10->area(), 0.1);
//     ASSERT_NEAR(62.83, c10->perimeter(), 0.1);
// }

// TEST_F(CaseShape, SortIncreasing)
// {
//     std::vector<Shape *> shapes;
//     shapes.push_back(c10);
//     shapes.push_back(s10);
//     std::sort(shapes.begin(), shapes.end(), [](Shape *s1, Shape *s2)
//               { return s1->area() < s2->area(); });
//     ASSERT_NEAR(100, shapes[0]->area(), 0.0001);
//     ASSERT_NEAR(314.159, shapes[1]->area(), 0.01);
// }

// TEST_F(CaseShape, SortDescending)
// {
//     std::vector<Shape *> shapes;
//     shapes.push_back(s10);
//     shapes.push_back(c10);

//     std::sort(shapes.begin(), shapes.end(), [](Shape *s1, Shape *s2)
//               { return s1->area() >= s2->area(); });

//     ASSERT_NEAR(314.159, shapes[0]->area(), 0.1);
//     ASSERT_NEAR(100, shapes[1]->area(), 0.0001);
// }