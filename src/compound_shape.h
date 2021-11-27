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
        for (Shape *shpae : _shpaes)
        {
            delete shpae;
        }
        _shpaes.clear();
    }

    double area() const override 
    { 
        double sum = 0;
        for (Shape* shpae : _shpaes)
        {
            sum += shpae->area();
        }
        return sum;
    }

    double perimeter() const override 
    {
        double sum = 0;
        for (Shape* shpae : _shpaes)
        {
            sum += shpae->perimeter();
        }
        return sum;
    }

    std::string info() const override 
    { 
        std::string contetnt = "";
        for (Shape* shpae : _shpaes)
        {
            contetnt += shpae->info() + "\n";
        }
        return "CompoundShape\n{\n" + contetnt + "}";
    }

    Iterator* createIterator() override { return new CompoundShapeIterator(_shpaes.begin(),_shpaes.end()); }

    void addShape(Shape* shape) override { _shpaes.push_back(shape); }

    void deleteShape(Shape* shape) override { _shpaes.remove(shape); }

    void accept(ShapeVisitor* visitor) override 
    {
        visitor->visitCompoundShape(this);
    }

private:
    std::list<Shape*> _shpaes;
};
