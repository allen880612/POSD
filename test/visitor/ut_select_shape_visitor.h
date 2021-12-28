#pragma once
#include "../../src/compound_shape.h"
#include "../../src/visitor/select_shape_visitor.h"
#include <cmath>

#define ACCURACY 0.001

class CaseSelectShapeVisitor : public ::testing::Test
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

// TEST_F(CaseSelectShapeVisitor, SelectShapeOnCircleNotFound) {
//     ShapeVisitor* visitor = new SelectShapeVisitor( [] (Shape* shape) {
//         return typeid(Rectangle) == typeid(*shape);
//         });
    
//     visitor->visitCircle((Circle*)c1);
//     Shape* result = visitor->getShape();

//     ASSERT_EQ(nullptr, visitor.getShape());
//     delete visitor;
// }

TEST_F(CaseSelectShapeVisitor, VisitCircle)
{
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(Circle) == typeid(*shape);
    });

    visitor.visitCircle((Circle*)c1);

    ASSERT_EQ(c1, visitor.getShape());
}

TEST_F(CaseSelectShapeVisitor, VisitRectangle)
{
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(Rectangle) == typeid(*shape);
    });

    visitor.visitRectangle((Rectangle*)r45);

    ASSERT_EQ(r45, visitor.getShape());
}

TEST_F(CaseSelectShapeVisitor, VisitTriangle)
{
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(Triangle) == typeid(*shape);
    });

    visitor.visitTriangle((Triangle*)triangle);

    ASSERT_EQ(triangle, visitor.getShape());
}

TEST_F(CaseSelectShapeVisitor, VisitCompound)
{
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(CompoundShape) == typeid(*shape);
    });

    visitor.visitCompoundShape((CompoundShape*)cs);

    ASSERT_EQ(cs, visitor.getShape());
}

TEST_F(CaseSelectShapeVisitor, SelectShapeOnCircleNotFound) {
    SelectShapeVisitor visitor( [] (Shape* shape) {
        return typeid(Rectangle) == typeid(*shape);
        });
    
    visitor.visitCircle((Circle*)c1);

    ASSERT_EQ(nullptr, visitor.getShape());
}

TEST_F(CaseSelectShapeVisitor, SelectCircleInCompound) {
    
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(Circle) == typeid(*shape);
    });

    visitor.visitCompoundShape((CompoundShape*)cs);

    ASSERT_EQ(c1, visitor.getShape());
}

TEST_F(CaseSelectShapeVisitor, SelectRectangleInCompound) {
    
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(Rectangle) == typeid(*shape);
    });

    visitor.visitCompoundShape((CompoundShape*)cs);

    ASSERT_EQ(r45, visitor.getShape());
}

TEST_F(CaseSelectShapeVisitor, SelectTriangleInCompound) {
    
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(Triangle) == typeid(*shape);
    });

    visitor.visitCompoundShape((CompoundShape*)cs);

    ASSERT_EQ(triangle, visitor.getShape());
}

TEST_F(CaseSelectShapeVisitor, SelectCompoundInCompound) {
    
    CompoundShape* target = (CompoundShape*)innerCompound;
    SelectShapeVisitor visitor([target](Shape* shape) {
        return shape == target;
    });

    visitor.visitCompoundShape((CompoundShape*)cs);

    ASSERT_EQ(innerCompound, visitor.getShape());
}

TEST_F(CaseSelectShapeVisitor, SelectInnerCircleInComplexCompound)
{
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(Circle) == typeid(*shape) && shape->area() > 5.0;
    });

    visitor.visitCompoundShape((CompoundShape*)cs);

    ASSERT_EQ(innerCircle, visitor.getShape());
}

TEST_F(CaseSelectShapeVisitor, SelectInnerRectangleInComplexCompound)
{
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(Rectangle) == typeid(*shape) && shape->area() < 20.0;
    });

    visitor.visitCompoundShape((CompoundShape*)cs);

    ASSERT_EQ(innerRectangle, visitor.getShape());
}

TEST_F(CaseSelectShapeVisitor, SelectInnerTriangleInComplexCompound)
{
    Triangle* find = (Triangle*)innerTriangle;
    SelectShapeVisitor visitor([find](Shape* shape) {
        return shape == find;
    });

    visitor.visitCompoundShape((CompoundShape*)cs);
    
    ASSERT_EQ(innerTriangle, visitor.getShape());
}
