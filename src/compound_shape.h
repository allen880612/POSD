#pragma once
#include "shape.h"

class CompoundShape : public Shape {
public:
    ~CompoundShape() { }

    double area() const override { }

    double perimeter() const override { }

    std::string info() const override { }

    Iterator* createIterator() override { }

    void addShape(Shape* shape) override { }

    void deleteShape(Shape* shape) override { }
private:
    std::list<Shape*> shpaes; 
};
