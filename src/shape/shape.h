#pragma once
#include <string>

class Iterator;
class Visitor;
class Shape {
public:
    virtual ~Shape() {};
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
    virtual Iterator* createIterator() = 0;
    virtual void addShape(Shape* shape) { throw std::string("Should not call this function!"); }
    virtual void deleteShape(Shape* shape) { throw std::string("Should not call this function!"); }
    virtual void accept(Visitor* Visitor) = 0;
};