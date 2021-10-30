#pragma once
#include <list>
#include "shape.h"

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

    Iterator* createIterator() override { }

    void addShape(Shape* shape) override { _shpaes.push_back(shape); }

    void deleteShape(Shape* shape) override { _shpaes.remove(shape); }
private:
    std::list<Shape*> _shpaes;
};
