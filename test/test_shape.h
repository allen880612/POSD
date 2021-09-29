#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include "../src/square.h"
#include "../src/circle.h"
#include "../src/shape.h"

TEST(CaseShape, CreationShape) {
    Shape* s = new Square(10.0);
    Circle* c = new Circle(10.0);
    ASSERT_NEAR(100, s->area(), 0.0001);
    ASSERT_NEAR(40, s->perimeter(), 0.0001);

    ASSERT_NEAR(314.15, c->area(), 0.1);
    ASSERT_NEAR(62.83, c->perimeter(), 0.1);
}

TEST(CaseShape, SortDescending) {
    vector<Shape*> shapes;
    shapes.push_back(new Square(10.0));
    shapes.push_back(new Circle(10.0));
    std::sort(shapes.begin(), shapes.end(), [](Shape* s1, Shape* s2) {
        return s1->area() < s2->area();
    });
    ASSERT_NEAR(100, shapes[0]->area(),0.0001);
    ASSERT_NEAR(314.159, shapes[1]->area(),0.01);
}

// lambda
TEST(CaseSquare, SortIncreasing) {
    Square squares[2] = {Square(10.0), Square(2.0)};
    std::sort(squares, squares + 2, [](Square s1, Square s2) {
        return s1.area() < s2.area();
    });
    ASSERT_NEAR(4, squares[0].area(),0.0001);
    ASSERT_NEAR(100, squares[1].area(),0.0001);
}