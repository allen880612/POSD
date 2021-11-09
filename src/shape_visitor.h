#pragma once
#include "visitor.h"
#include <string>

class Shape;
typedef bool (*ShapeConstraint)(Shape*); // pointer to function
class SelectShapeVisitor: public Visitor {
public:
    SelectShapeVisitor(): _result(nullptr), _constraint(nullptr) {}
    SelectShapeVisitor(ShapeConstraint constraint): _result(nullptr), _constraint(constraint) {}
    void visitCircle(Circle* c);
    void visitRectangle(Rectangle *square);
    void visitTriangle(Triangle *triangle);
    void visitCompoundShape(CompoundShape *cs);
    Shape* getShape();

private:
    Shape* _result;
    ShapeConstraint _constraint;
};

class ShapeInfoVisitor : public Visitor
{
public:
    ShapeInfoVisitor() : _indentLevel(0), _result("") {};
    ~ShapeInfoVisitor() {};
    void visitCircle(Circle *circle);
    void visitRectangle(Rectangle *square);
    void visitTriangle(Triangle *triangle);
    void visitCompoundShape(CompoundShape *cs);
    std::string getResult() { return _result; };

private:
    std::string getIndent();

    std::string _result;
    int _indentLevel;
};

