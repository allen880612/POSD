#pragma once
#include <list>
#include "shape.h"
#include "visitor/shape_visitor.h"
#include "iterator/compound_iterator.h"

#define CompoundShapeIterator CompoundIterator<std::list<Shape*>::iterator>
class CompoundShape : public Shape {
public:
    ~CompoundShape() 
    {  
        for (Shape *shpae : _shapes)
        {
            delete shpae;
        }
        _shapes.clear();
    }

    double area() const override 
    { 
        double sum = 0;
        for (Shape* shpae : _shapes)
        {
            sum += shpae->area();
        }
        return sum;
    }

    double perimeter() const override 
    {
        double sum = 0;
        for (Shape* shpae : _shapes)
        {
            sum += shpae->perimeter();
        }
        return sum;
    }

    std::string info() const override 
    { 
        return "CompoundShape";
    }

    Iterator* createIterator() override { return new CompoundShapeIterator(_shapes.begin(),_shapes.end()); }

    void addShape(Shape* shape) override { _shapes.push_back(shape); }

    void deleteShape(Shape* shape) override 
    { 
        _shapes.remove(shape);
        for (Shape* s : _shapes)
        {
            Iterator* shapeIt = s->createIterator();
            // compound shape sholud check it's children
            if (!shapeIt->isDone())
            {
                s->deleteShape(shape);
            }
            delete shapeIt;
        }
    }

    void accept(ShapeVisitor* visitor) override 
    {
        visitor->visitCompoundShape(this);
    }

private:
    std::list<Shape*> _shapes;
};
