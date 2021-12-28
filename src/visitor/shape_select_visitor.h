#pragma once

#include "../circle.h"
#include "../compound_shape.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "./shape_visitor.h"

template<class ShapeConstraint>
class ShapeSelectVisitor : public ShapeVisitor
{
public:
    ShapeSelectVisitor() : _result(nullptr) {}
    ShapeSelectVisitor(ShapeConstraint constraint) : _result(nullptr), _constraint(constraint) {}
    void visitCircle(Circle *circle);
    void visitRectangle(Rectangle *rectangle);
    void visitTriangle(Triangle *triangle);
    void visitCompoundShape(CompoundShape *compoundShape);
    Shape* getShape();

private:
    Shape* _result;
    ShapeConstraint _constraint;
};

template<typename ShapeConstraint>
void ShapeSelectVisitor<ShapeConstraint>::visitCircle(Circle * circle)
{
    if (_constraint(circle)) 
    {
        _result = circle;
    }
}

template<typename ShapeConstraint>
void ShapeSelectVisitor<ShapeConstraint>::visitRectangle(Rectangle *rectangle)
{
    if (_constraint(rectangle)) 
    {
        _result = rectangle;
    }
}

template<typename ShapeConstraint>
void ShapeSelectVisitor<ShapeConstraint>::visitTriangle(Triangle *triangle)
{
    if (_constraint(triangle)) 
    {
        _result = triangle;
    }
}

template<typename ShapeConstraint>
void ShapeSelectVisitor<ShapeConstraint>::visitCompoundShape(CompoundShape *cs)
{
    if (_constraint(cs)) 
    {
        _result = cs;
        return;
    } 
    else 
    {
        Iterator *it = cs->createIterator();
        while (!it->isDone())
        {
            it->currentItem()->accept(this);
            it->next();

            if (_result != nullptr) 
                break;
        }
        delete it;
        return;
    }
}

template<typename ShapeConstraint>
Shape* ShapeSelectVisitor<ShapeConstraint>::getShape()
{
    return _result;   
}