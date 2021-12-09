#pragma once
#include "../circle.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "../compound_shape.h"
#include <stack>

class ShapeBuilder {
public:
    void buildCircle(double radius);
    void buildRectangle(double length, double width);
    void buildTriangle(double x1, double y1, double x2, double y2);
    void buildCompoundBegin();
    void buildCompoundEnd();
    Shape* getShape();
private:
    bool topIsNonEmptyCompoundShape();
    std::stack<Shape*> _shapes;
};

void ShapeBuilder::buildCircle(double radius) {
    _shapes.push(new Circle(radius));
}

void ShapeBuilder::buildRectangle(double length, double width) {
    _shapes.push(new Rectangle(length, width));
}

void ShapeBuilder::buildTriangle(double x1, double y1, double x2, double y2) {
    TwoDimensionalVector vec1(x1, y1);
    TwoDimensionalVector vec2(x2, y2);
    _shapes.push(new Triangle(vec1, vec2));
}

void ShapeBuilder::buildCompoundBegin() {
    _shapes.push(new CompoundShape());
}

bool ShapeBuilder::topIsNonEmptyCompoundShape() {
    Shape* top = _shapes.top();
    bool isCompoundShape = typeid(*top) == typeid(CompoundShape);
    bool isNonEmptyCompoundShape = isCompoundShape && (top->area() != 0);
    return !isCompoundShape || isNonEmptyCompoundShape;
}

void ShapeBuilder::buildCompoundEnd() {
    std::list<Shape*> components;
    while(topIsNonEmptyCompoundShape()) {
        components.push_back(_shapes.top());
        _shapes.pop();
    }
    Shape* compound = _shapes.top();
    for(auto it = components.rbegin() ; it != components.rend() ; it++){
        compound->addShape(*it);
    }
}

Shape* ShapeBuilder::getShape(){
    Shape* result = _shapes.top();
    _shapes.pop();
    return result;
}