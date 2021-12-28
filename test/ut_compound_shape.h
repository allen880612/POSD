#pragma once
#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/iterator/iterator.h"
#include "../src/visitor/shape_info_visitor.h"
#include <cmath>

#define ACCURACY 0.001

class CaseCompoundShape : public ::testing::Test
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

TEST_F(CaseCompoundShape, CreateSuccessfully)
{
    ASSERT_NO_THROW(CompoundShape());
}

TEST_F(CaseCompoundShape, Add)
{
    Shape* c2 = new Circle(2.0);
    cs->addShape(c2);

    Iterator* it = cs->createIterator(); 
    ASSERT_EQ(c1, it->currentItem());
    it->next();
    ASSERT_EQ(r45, it->currentItem());
    it->next();
    ASSERT_EQ(c2, it->currentItem());
    delete it;
}

TEST_F(CaseCompoundShape, Delete)
{
    cs->deleteShape(c1);
    Iterator* it = cs->createIterator(); 

    ASSERT_EQ(r45, it->currentItem());
    it->next();
    ASSERT_TRUE(it->isDone());
    delete it;
}

TEST_F(CaseCompoundShape, DeleteInnerShape)
{
    Shape* c = new Circle(2);
    Shape* r = new Rectangle(3 ,4);
    Shape* cs2 = new CompoundShape();
    cs2->addShape(c);
    cs2->addShape(r);
    cs->addShape(cs2);

    const double originalArea = M_PI + 4*5 + 2*2 * M_PI + 3*4;
    const double expectedArea = originalArea - 3*4;
    cs->deleteShape(r);

    ASSERT_NEAR(expectedArea, cs->area(), ACCURACY);
}

TEST_F(CaseCompoundShape, Area)
{
    ASSERT_NEAR(M_PI + 4*5, cs->area(), ACCURACY);
}

TEST_F(CaseCompoundShape, Perimeter)
{
    ASSERT_NEAR(18+2*M_PI, cs->perimeter(), ACCURACY);
}

TEST_F(CaseCompoundShape, Info)
{
    std::string expected = "CompoundShape";
    ASSERT_EQ(expected, cs->info());
}


TEST_F(CaseCompoundShape, SimpleInfoByVisitor)
{
    std::string expected = "CompoundShape {\n"
                           "  " + c1->info() +"\n"
                           "  " + r45->info() + "\n"
                           "}\n";
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    cs->accept(visitor);
    ASSERT_EQ(expected, visitor->getResult());
    delete visitor;
}

TEST_F(CaseCompoundShape, ComplexInfoByVisitor)
{
    Shape* c = new Circle(1.1);
    Shape* r = new Rectangle(3.14 ,4);
    std::string expected = "CompoundShape {\n"
                           "  " + c1->info() + "\n"
                           "  " + r45->info() + "\n"
                           "  CompoundShape {\n"
                           "    " + c->info() + "\n"
                           "    " + r->info() + "\n"
                           "  }\n"
                           "}\n";

    Shape* cs2 = new CompoundShape();
    cs2->addShape(c);
    cs2->addShape(r);
    cs->addShape(cs2);

    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    cs->accept(visitor);
    ASSERT_EQ(expected, visitor->getResult());
    delete visitor;
}