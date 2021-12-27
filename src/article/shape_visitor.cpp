#include "shape_visitor.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "rectangle.h"
#include "compound_shape.h"

void SelectShapeVisitor::visitCircle(Circle* circle) {
    if (_constraint) {
        if (_constraint(circle)) {
            _result = circle; 
        }
    }
}

void SelectShapeVisitor::visitRectangle(Rectangle* rectangle) {
    if (_constraint) {
        if (_constraint(rectangle)) {
            _result = rectangle; 
        }
    }
}

void SelectShapeVisitor::visitTriangle(Triangle* triangle) {
    if (_constraint) {
        if (_constraint(triangle)) {
            _result = triangle; 
        }
    }
}

void SelectShapeVisitor::visitCompoundShape(CompoundShape* cs) {
    Iterator* it = cs->createIterator();
    for (it->first(); !it->isDone(); it->next()) {
        it->currentItem()->accept(this);
    }
    delete it;
}

Shape* SelectShapeVisitor::getShape() {
    return _result;
}

void ShapeInfoVisitor::visitCircle(Circle *circle)
{
    _result += getIndent();
    _result += circle->info() + "\n";
}

void ShapeInfoVisitor::visitRectangle(Rectangle *rectangle)
{
    _result += getIndent();
    _result += rectangle->info() + "\n";
}

void ShapeInfoVisitor::visitTriangle(Triangle *triangle)
{
    _result += getIndent();
    _result += triangle->info() + "\n";
}

void ShapeInfoVisitor::visitCompoundShape(CompoundShape *cs)
{
    std::string start = getIndent() + "CompoundShape\n" + getIndent() + "{\n";
    std::string end = getIndent() + "}";
    if (_indentLevel != 0) {end += "\n";}
    
    _result += start;
    _indentLevel += 2;
    Iterator* it = cs->createIterator();
    while(!it->isDone())
    {
        it->currentItem()->accept(this);
        it->next();
    }
    _result += end;
    delete it;
}

std::string ShapeInfoVisitor::getIndent()
{
    std::string indent = "";
    for (int i = 0; i < _indentLevel; i++)
    {
        indent += " ";
    }
    return indent;
}
