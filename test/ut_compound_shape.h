#pragma once
#include <gtest/gtest.h>
#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
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

// TEST_F(CaseCompoundShape, Add)
// {
//     cs->addShape(c1);
//     cs->addShape(r45);

//     ASSERT_EQ(c1, cs->area());
// }

TEST_F(CaseCompoundShape, Area)
{
    ASSERT_NEAR(M_PI + 4*5, cs->area(), ACCURACY);
}

TEST_F(CaseCompoundShape, Perimeter)
{
    ASSERT_NEAR(18+2*M_PI, cs->perimeter(), ACCURACY);
}

TEST_F(CaseCompoundShape, SimpleInfo)
{
    std::string expected = "CompoundShape\n{\n"
                         + c1->info() + "\n"
                         + r45->info()
                         + "\n}";
    ASSERT_EQ(expected, cs->info());
}

TEST_F(CaseCompoundShape, ComplexInfo)
{
    Shape* c = new Circle(1.1);
    Shape* r = new Rectangle(3.14 ,4);
    std::string expected = "CompoundShape\n{\n"
                         + c1->info() + "\n"
                         + r45->info() + "\n"
                         + "CompoundShape\n{\n"
                         + c->info() + "\n"
                         + r->info() + "\n"
                         + "}\n"
                         + "}";

    Shape* cs2 = new CompoundShape();
    cs2->addShape(c);
    cs2->addShape(r);
    cs->addShape(cs2);
}
