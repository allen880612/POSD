#pragma once
#include "../src/circle.h"
#include "../src/visitor/shape_info_visitor.h"

#define CIRCLE_EXCEPTION_MSG std::string("Circle created by positive double radius.")
#define ACCURACY 0.001

class CaseCircle : public ::testing::Test
{
protected:
    void SetUp() override
    {
        c10 = new Circle(10.0);
    }

    void TearDown() override
    {
        delete c10;
    }

    Shape* c10;
};

TEST_F(CaseCircle, CircleShouldBeAShape) {
    ASSERT_EQ(typeid(Circle), typeid(*c10));
}

TEST_F(CaseCircle, CreateSuccessfully) {
    ASSERT_NO_THROW(Circle s(10.0));
}

TEST_F(CaseCircle, CreateWWithNegativeRadiusShouldThrowException) {
    ASSERT_THROW(Circle c(-1), std::invalid_argument);
}

TEST_F(CaseCircle, CreateWWithZeroRadiusShouldThrowException) {
    ASSERT_THROW(Circle c(0), std::invalid_argument);
}

TEST_F(CaseCircle, Area) {
    ASSERT_NEAR(314.159, c10->area(), ACCURACY);
}

TEST_F(CaseCircle, Perimeter) {
    ASSERT_NEAR(62.8318, c10->perimeter(), ACCURACY);
}

TEST_F(CaseCircle, Info) {
    const std::string expected = "Circle (10.00)";
    ASSERT_EQ(expected, c10->info());
}

TEST_F(CaseCircle, InfoShouldOnlyShowTwoDecimal) {
    Circle c(10.123);
    const std::string expected = "Circle (10.12)";
    ASSERT_EQ(expected, c.info());
}

TEST_F(CaseCircle, AddShouldThrowException) {
    ASSERT_ANY_THROW(c10->addShape(nullptr));
}

TEST_F(CaseCircle, DeleteShouldThrowException) {
    ASSERT_ANY_THROW(c10->deleteShape(nullptr));
}

TEST_F(CaseCircle, IsDoneOfCreateIteratorShouldBeTrue) {
    Iterator* it = c10->createIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}

TEST_F(CaseCircle, acceptShapeInfoVisitor) {
    std::string expected = "Circle (10.00)\n";
    ShapeInfoVisitor visitor;
    
    c10->accept(&visitor);

    ASSERT_EQ(expected, visitor.getResult());
}