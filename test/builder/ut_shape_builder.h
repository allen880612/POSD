#pragma once
#include "../../src/builder/shape_builder.h"

#include <cmath>
#define ACCURACY 0.001

class CaseShapeBuilder : public ::testing::Test
{
protected:
    void SetUp() override
    {
        builder = ShapeBuilder::getInstance();
        TwoDimensionalVector vec_30(3.0, 0.0);
        TwoDimensionalVector vec_t04(0.0, 4.0);
        triagle = new Triangle(vec_30, vec_t04);
        rectangle = new Rectangle(3.14, 4.0);
        circle = new Circle(1.0);
    }

    void TearDown() override
    {
        delete triagle;
        delete rectangle;
        delete circle;
    }

    ShapeBuilder* builder;
    Triangle* triagle;
    Circle* circle;
    Rectangle* rectangle;
};

TEST_F(CaseShapeBuilder, buildCircle) {
    double expected = M_PI;

    builder->buildCircle(1.0);
    Shape* s = builder->getShape();

    ASSERT_EQ(typeid(Circle), typeid(*s));
    ASSERT_NEAR(expected, s->area(), ACCURACY);
}

TEST_F(CaseShapeBuilder, buildRectangle) {
    double expected = 3.14 * 4.0;

    builder->buildRectangle(3.14, 4.0);
    Shape* s = builder->getShape();

    ASSERT_EQ(typeid(Rectangle), typeid(*s));
    ASSERT_NEAR(expected, s->area(), ACCURACY);
}

TEST_F(CaseShapeBuilder, buildTriangle) {
    double expected = 3 * 4 / 2;

    builder->buildTriangle(3.0, 0.0, 0.0, 4.0);
    Shape* s = builder->getShape();

    ASSERT_EQ(typeid(Triangle), typeid(*s));
    ASSERT_NEAR(expected, s->area(), ACCURACY);
}

TEST_F(CaseShapeBuilder, buildSimpleCompoundShape) {
    double expected = M_PI + 3.14 * 4.0 + 3 * 4 / 2;

    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildRectangle(3.14, 4.0);
    builder->buildTriangle(3.0, 0.0, 0.0, 4.0);
    builder->buildCompoundEnd();
    Shape* s = builder->getShape();

    ASSERT_EQ(typeid(CompoundShape), typeid(*s));
    ASSERT_NEAR(expected, s->area(), ACCURACY);
}

TEST_F(CaseShapeBuilder, buildEmptyCompoundShape) {
    double expected = 0;

    builder->buildCompoundBegin();
    builder->buildCompoundEnd();
    Shape* s = builder->getShape();

    ASSERT_EQ(typeid(CompoundShape), typeid(*s));
    ASSERT_NEAR(expected, s->area(), ACCURACY);
}

TEST_F(CaseShapeBuilder, buildComplexCompoundShape) {
    double expected = (M_PI + 3.14 * 4.0 + 3 * 4 / 2) * 2;

    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildTriangle(3.0, 0.0, 0.0, 4.0);
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildRectangle(3.14, 4.0);
    builder->buildTriangle(3.0, 0.0, 0.0, 4.0);
    builder->buildCompoundEnd();
    builder->buildRectangle(3.14, 4.0);
    builder->buildCompoundEnd();
    Shape* s = builder->getShape();

    ASSERT_EQ(typeid(CompoundShape), typeid(*s));
    ASSERT_NEAR(expected, s->area(), ACCURACY);
}

TEST_F(CaseShapeBuilder, builderShouldBeSingleton) {
    ShapeBuilder* builder1 = ShapeBuilder::getInstance();
    ShapeBuilder* builder2 = ShapeBuilder::getInstance();
    ASSERT_EQ(builder1, builder2);

}