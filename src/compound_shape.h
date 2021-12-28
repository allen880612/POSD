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
        // std::cout << "delete compound area: " << area() << std::endl;
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
        auto it = _shapes.begin();
        while (it != _shapes.end())
        {
            if(*it == shape)
            {
                delete *it;
                it = _shapes.erase(it);
                break;
            }
            else
            {
                Iterator *shapeIt = (*it)->createIterator();
                if(!shapeIt->isDone())
                {
                    (*it)->deleteShape(shape);
                    std::cout << "nn" << std::endl;
                }
                delete shapeIt;
            }
            it++;
        }
    }

    void accept(ShapeVisitor* visitor) override 
    {
        visitor->visitCompoundShape(this);
    }

private:
    std::list<Shape*> _shapes;
};
