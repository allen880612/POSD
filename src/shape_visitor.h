#pragma once
// #include "visitor.h"
#include <string>

// template <class ShapeConstrain>
// class SelectShapeVisitor : public Visitor
// {
// public:
//     SelectShapeVisitor(ShapeConstrain constrain) : _result(nullptr), _constrain(constrain) {}
//     ~SelectShapeVisitor(){};
//     void visitCircle(Circle *circle);
//     void visitRectangle(Rectangle *square);
//     void visitTriangle(Triangle *triangle);
//     void visitCompoundShape(CompoundShape *cs);

// private:
//     Shape *_result;
//     ShapeConstrain _constrain;
// };

class Circle;
class Rectangle;
class Triangle;
class CompoundShape;

class Visitor
{
public:
    virtual ~Visitor() {}
    virtual void visitCircle(Circle *circle) = 0;
    virtual void visitRectangle(Rectangle *square) = 0;
    virtual void visitTriangle(Triangle *triangle) = 0;
    virtual void visitCompoundShape(CompoundShape *cs) = 0;
protected:
    Visitor() {}
};

class ShapeInfoVisitor : public Visitor
{
public:
    ShapeInfoVisitor() : _indentLevel(0), _result(nullptr) {}
    // ~ShapeInfoVisitor() override {}
    void visitCircle(Circle *circle);
    void visitRectangle(Rectangle *square);
    void visitTriangle(Triangle *triangle);
    void visitCompoundShape(CompoundShape *cs);
    std::string getResult() { return _result; }

private:
    std::string getIndent();

    std::string _result;
    int _indentLevel;
};