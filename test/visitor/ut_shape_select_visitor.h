#pragma once
#include "../../src/compound_shape.h"
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/visitor/shape_select_visitor.h"
#include <cmath>

#define ACCURACY 0.001

class CaseShapeSelectVisitor : public ::testing::Test
{
protected:
    void SetUp() override
    {
        c1 = new Circle(1.0);
        r45 = new Rectangle(4.0, 5.0);
        triangle = new Triangle(TwoDimensionalVector(3.0, 0.0), TwoDimensionalVector(0.0, 4.0));
        cs = new CompoundShape();

        cs->addShape(c1);
        cs->addShape(r45);
        cs->addShape(triangle);

        innerCompound = new CompoundShape();
        innerCircle = new Circle(10.0);
        innerRectangle = new Rectangle(3.14 ,4);
        innerTriangle = new Triangle(TwoDimensionalVector(5.0, 0.0), TwoDimensionalVector(0.0, 12.0));
        innerCompound->addShape(innerCircle);
        innerCompound->addShape(innerRectangle);
        innerCompound->addShape(innerTriangle);
        
        cs->addShape(innerCompound);
    }

    void TearDown() override
    {
        delete cs;
    }

    Shape* cs;
    Shape* c1;
    Shape* r45;
    Shape* triangle;

    Shape* innerCompound;
    Shape* innerCircle;
    Shape* innerRectangle;
    Shape* innerTriangle;

};

// TEST_F(CaseShapeSelectVisitor, SelectShapeOnCircleNotFound) {
//     ShapeVisitor* visitor = new ShapeSelectVisitor( [] (Shape* shape) {
//         return typeid(Rectangle) == typeid(*shape);
//         });
    
//     visitor->visitCircle((Circle*)c1);
//     Shape* result = visitor->getShape();

//     ASSERT_EQ(nullptr, visitor.getShape());
//     delete visitor;
// }

TEST_F(CaseShapeSelectVisitor, VisitCircle)
{
    ShapeSelectVisitor visitor([](Shape* shape) {
        return typeid(Circle) == typeid(*shape);
    });

    visitor.visitCircle((Circle*)c1);

    ASSERT_EQ(c1, visitor.getShape());
}

TEST_F(CaseShapeSelectVisitor, VisitRectangle)
{
    ShapeSelectVisitor visitor([](Shape* shape) {
        return typeid(Rectangle) == typeid(*shape);
    });

    visitor.visitRectangle((Rectangle*)r45);

    ASSERT_EQ(r45, visitor.getShape());
}

TEST_F(CaseShapeSelectVisitor, VisitTriangle)
{
    ShapeSelectVisitor visitor([](Shape* shape) {
        return typeid(Triangle) == typeid(*shape);
    });

    visitor.visitTriangle((Triangle*)triangle);

    ASSERT_EQ(triangle, visitor.getShape());
}

TEST_F(CaseShapeSelectVisitor, SelectShapeOnCircleNotFound) {
    ShapeSelectVisitor visitor( [] (Shape* shape) {
        return typeid(Rectangle) == typeid(*shape);
        });
    
    visitor.visitCircle((Circle*)c1);

    ASSERT_EQ(nullptr, visitor.getShape());
}

TEST_F(CaseShapeSelectVisitor, SelectCircleInCompound) {
    
    ShapeSelectVisitor visitor([](Shape* shape) {
        return typeid(Circle) == typeid(*shape);
    });

    visitor.visitCompoundShape((CompoundShape*)cs);

    ASSERT_EQ(c1, visitor.getShape());
}

TEST_F(CaseShapeSelectVisitor, SelectRectangleInCompound) {
    
    ShapeSelectVisitor visitor([](Shape* shape) {
        return typeid(Rectangle) == typeid(*shape);
    });

    visitor.visitCompoundShape((CompoundShape*)cs);

    ASSERT_EQ(r45, visitor.getShape());
}

TEST_F(CaseShapeSelectVisitor, SelectTriangleInCompound) {
    
    ShapeSelectVisitor visitor([](Shape* shape) {
        return typeid(Triangle) == typeid(*shape);
    });

    visitor.visitCompoundShape((CompoundShape*)cs);

    ASSERT_EQ(triangle, visitor.getShape());
}

TEST_F(CaseShapeSelectVisitor, SelectInnerCircleInComplexCompound)
{
    ShapeSelectVisitor visitor([](Shape* shape) {
        return typeid(Circle) == typeid(*shape) && shape->area() > 5.0;
    });

    visitor.visitCompoundShape((CompoundShape*)cs);

    ASSERT_EQ(innerCircle, visitor.getShape());
}

TEST_F(CaseShapeSelectVisitor, SelectInnerRectangleInComplexCompound)
{
    ShapeSelectVisitor visitor([](Shape* shape) {
        return typeid(Rectangle) == typeid(*shape) && shape->area() < 20.0;
    });

    visitor.visitCompoundShape((CompoundShape*)cs);

    ASSERT_EQ(innerRectangle, visitor.getShape());
}

TEST_F(CaseShapeSelectVisitor, SelectInnerTriangleInComplexCompound)
{
    Triangle* find = (Triangle*)innerTriangle;
    ShapeSelectVisitor visitor([find](Shape* shape) {
        return shape == find;
    });

    visitor.visitCompoundShape((CompoundShape*)cs);
    
    ASSERT_EQ(innerTriangle, visitor.getShape());
}
