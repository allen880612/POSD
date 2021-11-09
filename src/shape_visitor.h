#pragma once

class Shape; 
class Circle; 
class Rectangle;
class CompoundShape; 

class Visitor {
public:
    virtual ~Visitor() {}
    virtual void visitCircle(Circle* c) = 0;

protected:
    Visitor() {}
};

typedef bool (*ShapeConstraint)(Shape*); // pointer to function
class SelectShapeVisitor: public Visitor {
public:
    SelectShapeVisitor(): _result(nullptr), _constraint(nullptr) {}
    SelectShapeVisitor(ShapeConstraint constraint): _result(nullptr), _constraint(constraint) {}
    void visitCircle(Circle* c);
    Shape* getShape();

private:
    Shape* _result;
    ShapeConstraint _constraint;
};


