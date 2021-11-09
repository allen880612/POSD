#pragma once
#include <gtest/gtest.h>
#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/shape_visitor.h"
#include <cmath>

#define ACCURACY 0.001

class CaseVisitor : public ::testing::Test
{
protected:
    void SetUp() override
    {
        c1 = new Circle(1.0);
        r45 = new Rectangle(4.0, 5.0);
        cs = new CompoundShape();

        cs->addShape(c1);
        cs->addShape(r45);
    }

    void TearDown() override
    {
        delete cs;
    }

    Shape* c1;
    Shape* r45;
    Shape* cs;
};

TEST(CaseVisitor, SelectShapeOnCircleNotFound) {
    Circle* c1 = new Circle(1.0);
    
    SelectShapeVisitor* visitor = new SelectShapeVisitor([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });
    // c1->accept(visitor);
    visitor->visitCircle(c1);
    Shape* result = visitor->getShape();

    ASSERT_EQ(nullptr, result);
    delete c1;
    delete visitor;
} 

// TEST_F(CaseVisitor, SimpleInfo)
// {
//     std::string expected = "CompoundShape\n"
//                            "{\n"
//                            "  " + c1->info() +"\n"
//                            "  " + r45->info() + "\n"
//                            "}";
//     ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
//     visitor->visitCompoundShape((CompoundShape*)cs);

//     ASSERT_EQ(expected, visitor->getResult());
// }

// TEST_F(CaseVisitor, ComplexInfo)
// {
//     Shape* c = new Circle(1.1);
//     Shape* r = new Rectangle(3.14 ,4);
//     std::string expected = "CompoundShape\n{\n"
//                          + c1->info() + "\n"
//                          + r45->info() + "\n"
//                          + "CompoundShape\n{\n"
//                          + c->info() + "\n"
//                          + r->info() + "\n"
//                          + "}\n"
//                          + "}";

//     Shape* cs2 = new CompoundShape();
//     cs2->addShape(c);
//     cs2->addShape(r);
//     cs->addShape(cs2);
// }
