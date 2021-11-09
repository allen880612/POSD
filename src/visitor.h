#pragma once

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