#pragma once
#include "../../src/compound_shape.h"
#include "../../src/circle.h"
#include "../../src/rectangle.h"
#include "../../src/visitor/shape_info_visitor.h"
#include <cmath>

#define ACCURACY 0.001

class CaseVisitor : public ::testing::Test
{
protected:
    void SetUp() override
    {
        shapeInfoVisitor = new ShapeInfoVisitor();
        c1 = new Circle(1.0);
        r45 = new Rectangle(4.0, 5.0);
        cs = new CompoundShape();

        cs->addShape(c1);
        cs->addShape(r45);
    }

    void TearDown() override
    {
        delete cs;
        delete shapeInfoVisitor;
    }

    Shape* c1;
    Shape* r45;
    Shape* cs;
    ShapeInfoVisitor* shapeInfoVisitor;
};

TEST_F(CaseVisitor, SimpleInfo)
{
    std::string expected = "CompoundShape{\n"
                           "  " + c1->info() +"\n"
                           "  " + r45->info() + "\n"
                           "}\n";
    
    shapeInfoVisitor->visitCompoundShape((CompoundShape*)cs);

    ASSERT_EQ(expected, shapeInfoVisitor->getResult());
}

TEST_F(CaseVisitor, ComplexInfo)
{
    Shape* c = new Circle(1.1);
    Shape* r = new Rectangle(3.14 ,4);
    std::string expected = "CompoundShape{\n"
                           "  " + c1->info() + "\n"
                           "  " + r45->info() + "\n"
                           "  CompoundShape{\n"
                           "    " + c->info() + "\n"
                           "    " + r->info() + "\n"
                           "  }\n"
                           "}\n";

    Shape* cs2 = new CompoundShape();
    cs2->addShape(c);
    cs2->addShape(r);
    cs->addShape(cs2);

    shapeInfoVisitor->visitCompoundShape((CompoundShape*)cs);
    ASSERT_EQ(expected, shapeInfoVisitor->getResult());
}
