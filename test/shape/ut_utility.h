#pragma once
#include "../src/iterator/iterator.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/compound_shape.h"
#include "../src/utility.h"

class CaseUtility : public ::testing::Test
{
protected:
    void SetUp() override
    {
        c1 = new Circle(1.0);
        r34 = new Rectangle(3.0, 4.0);
        r45 = new Rectangle(4.0, 5.0);
        cs = new CompoundShape();

        cs->addShape(r34);
        cs->addShape(r45);
        cs->addShape(c1);
    }

    void TearDown() override
    {
        delete cs;
    }

    Shape* c1;
    Shape* r34;
    Shape* r45;
    Shape* cs;
};

TEST_F(CaseUtility, SelectShapeByAreaEqual) {
    Shape* result = selectShape(cs, [&] (Shape* shape) -> bool {
        return shape->area() == 20;
    });
    ASSERT_EQ(r45, result);
}

TEST_F(CaseUtility, SelectShapeByAreaRange) {
    Shape* result = selectShape(cs, [&] (Shape* shape) -> bool {
        return shape->area() < 20 && shape->area() > 5;
    });
    ASSERT_EQ(r34, result);
}

TEST_F(CaseUtility, SelectShapeByType) {
    Shape* result = selectShape(cs, [&] (Shape* shape) -> bool {
        return typeid(Circle) == typeid(*shape);
    });
    ASSERT_EQ(c1, result);
}

TEST_F(CaseUtility, SelectShapeByPerimeter) {
    Shape* result = selectShape(cs, [&] (Shape* shape) -> bool {
        return shape->perimeter() < 14 && shape->perimeter() > 5;
    });
    ASSERT_EQ(c1, result);
}

TEST_F(CaseUtility, SelectShapeNoMatchShouldGetNull) {
    Shape* result = selectShape(cs, [&] (Shape* shape) -> bool {
        return typeid(Triangle) == typeid(*shape);
    });
    ASSERT_EQ(nullptr, result);
}
