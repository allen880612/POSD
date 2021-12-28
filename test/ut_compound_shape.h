#pragma once
#include "../src/compound_shape.h"
#include "../src/visitor/shape_info_visitor.h"
#include "../src/visitor/select_shape_visitor.h"
#include <cmath>

#define ACCURACY 0.001

class CaseCompoundShape : public ::testing::Test
{
protected:
    void SetUp() override
    {
        cs = new CompoundShape();
        c1 = new Circle(1.0);
        r45 = new Rectangle(4.0, 5.0);
        triangle = new Triangle(TwoDimensionalVector(3.0, 0.0), TwoDimensionalVector(0.0, 4.0));

        cs->addShape(c1);
        cs->addShape(r45);
        cs->addShape(triangle);
        compoundArea = M_PI + 4*5 + 4*3/2;

        innerCompound = nullptr;
        innerCircle = nullptr;
        innerRectangle = nullptr;
        innerTriangle = nullptr;
    }

    void TearDown() override
    {
        delete cs;
    }

    void addInnerCompound()
    {
        innerCompound = new CompoundShape();
        innerCircle = new Circle(10.0);
        innerRectangle = new Rectangle(4 ,5);
        innerTriangle = new Triangle(TwoDimensionalVector(5.0, 0.0), TwoDimensionalVector(0.0, 12.0));

        innerCompound->addShape(innerCircle);
        innerCompound->addShape(innerRectangle);
        innerCompound->addShape(innerTriangle);

        cs->addShape(innerCompound);
        compoundArea += 10*10*M_PI + 4*5 + 5*12/2;
    }

    Shape* cs;
    Shape* c1;
    Shape* r45;
    Shape* triangle;
    double compoundArea;

    Shape* innerCompound;
    Shape* innerCircle;
    Shape* innerRectangle;
    Shape* innerTriangle;
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
    ASSERT_EQ(triangle, it->currentItem());
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
    it->next();
    ASSERT_TRUE(it->isDone());
    delete it;
}

TEST_F(CaseCompoundShape, DeleteInnerShape)
{
    addInnerCompound();

    const double originalArea = compoundArea;
    const double expectedArea = originalArea - innerRectangle->area();
    cs->deleteShape(innerRectangle);

    ASSERT_NEAR(expectedArea, cs->area(), ACCURACY);
}

TEST_F(CaseCompoundShape, Area)
{
    ASSERT_NEAR(compoundArea, cs->area(), ACCURACY);
}

TEST_F(CaseCompoundShape, Perimeter)
{
    ASSERT_NEAR(18+2*M_PI+12, cs->perimeter(), ACCURACY);
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
                           "  " + triangle->info() + "\n"
                           "}\n";
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    cs->accept(visitor);
    ASSERT_EQ(expected, visitor->getResult());
    delete visitor;
}

TEST_F(CaseCompoundShape, ComplexInfoByVisitor)
{
    addInnerCompound();
    std::string expected = "CompoundShape {\n"
                           "  " + c1->info() + "\n"
                           "  " + r45->info() + "\n"
                           "  " + triangle->info() + "\n"
                           "  CompoundShape {\n"
                           "    " + innerCircle->info() + "\n"
                           "    " + innerRectangle->info() + "\n"
                           "    " + innerTriangle->info() + "\n"
                           "  }\n"
                           "}\n";

    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    cs->accept(visitor);
    ASSERT_EQ(expected, visitor->getResult());
    delete visitor;
}

TEST_F(CaseCompoundShape, AcceptSelectShapeVisitor)
{
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(CompoundShape) == typeid(*shape);
    });

    cs->accept(&visitor);

    ASSERT_EQ(cs, visitor.getShape());
}

TEST_F(CaseCompoundShape, SelectCircleInCompound) {
    
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(Circle) == typeid(*shape);
    });

    cs->accept(&visitor);

    ASSERT_EQ(c1, visitor.getShape());
}

TEST_F(CaseCompoundShape, SelectRectangleInCompound) {
    
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(Rectangle) == typeid(*shape);
    });

    cs->accept(&visitor);

    ASSERT_EQ(r45, visitor.getShape());
}

TEST_F(CaseCompoundShape, SelectTriangleInCompound) {
    
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(Triangle) == typeid(*shape);
    });

    cs->accept(&visitor);

    ASSERT_EQ(triangle, visitor.getShape());
}

TEST_F(CaseCompoundShape, SelectCompoundInCompound) {
    
    CompoundShape* innerCompound = new CompoundShape();
    cs->addShape(innerCompound);
    SelectShapeVisitor visitor([innerCompound](Shape* shape) {
        return shape == innerCompound;
    });

    cs->accept(&visitor);

    ASSERT_EQ(innerCompound, visitor.getShape());
}

TEST_F(CaseCompoundShape, SelectInnerCircleInComplexCompound)
{
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(Circle) == typeid(*shape) && shape->area() > 5.0;
    });

    cs->accept(&visitor);

    ASSERT_EQ(innerCircle, visitor.getShape());
}

TEST_F(CaseCompoundShape, SelectInnerRectangleInComplexCompound)
{
    SelectShapeVisitor visitor([](Shape* shape) {
        return typeid(Rectangle) == typeid(*shape) && shape->area() < 20.0;
    });

    cs->accept(&visitor);

    ASSERT_EQ(innerRectangle, visitor.getShape());
}

TEST_F(CaseCompoundShape, SelectInnerTriangleInComplexCompound)
{
    Triangle* find = (Triangle*)innerTriangle;
    SelectShapeVisitor visitor([find](Shape* shape) {
        return shape == find;
    });

    cs->accept(&visitor);
    
    ASSERT_EQ(innerTriangle, visitor.getShape());
}

// Should move to utility test
// TEST_F(CaseCompoundShape, DeleteSelectedShape)
// {   
//     // delete c1 by area
//     Shape* result = selectShape(cs, [&] (Shape* shape) -> bool {
//         return typeid(*shape) == typeid(Circle);
//     });

//     cs->deleteShape(result);
//     Iterator* it = cs->createIterator();

//     // first item is r45, instead of c1 now
//     ASSERT_EQ(r45, it->currentItem());
// }