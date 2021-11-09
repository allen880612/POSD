#pragma once
#include "shape_visitor.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "rectangle.h"
#include "compound_shape.h"

void ShapeInfoVisitor::visitCircle(Circle *circle)
{
    _result = getIndent();
    _result += circle->info() + "\n";
}

void ShapeInfoVisitor::visitRectangle(Rectangle *rectangle)
{
    _result = getIndent();
    _result += rectangle->info() + "\n";
}

void ShapeInfoVisitor::visitTriangle(Triangle *triangle)
{
    _result = getIndent();
    _result += triangle->info() + "\n";
}

void ShapeInfoVisitor::visitCompoundShape(CompoundShape *cs)
{
    std::string start = getIndent() + "CompoundShape\n";
    std::string end = getIndent() + "}";
    _result += start;

    _indentLevel += 2;
    Iterator* it = cs->createIterator();
    while(!it->isDone())
    {
        it->currentItem()->accept(this);
    }
    
    _result += end;
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
