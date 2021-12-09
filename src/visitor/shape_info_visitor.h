#pragma once

#include <string>

#include "../circle.h"
#include "../compound_shape.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "./shape_visitor.h"

class ShapeInfoVisitor : public ShapeVisitor
{
public:
    void visitCircle(Circle *circle);
    void visitRectangle(Rectangle *rectangle);
    void visitTriangle(Triangle *triangle);
    void visitCompoundShape(CompoundShape *compoundShape);
    std::string getResult() { return _result; }

private:
    int _indentLevel = 0;
    std::string _result = "";
    std::string getIndent();
};

std::string ShapeInfoVisitor::getIndent()
{
    std::string indent = "";
    for (int i = 0; i < _indentLevel; i++)
    {
        indent += " ";
    }
    return indent;
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
    std::string start = getIndent() + "CompoundShape {\n";
    std::string end = getIndent() + "}\n";

    _result += start;
    _indentLevel += 2;
    Iterator *it = cs->createIterator();
    while (!it->isDone())
    {
        it->currentItem()->accept(this);
        it->next();
    }
    _result += end;
}