#pragma once
#include "visitor.h"
#include <string>

class Article;

class ShapeInfoVisitor : public Visitor
{
public:
    ShapeInfoVisitor() : _indentLevel(0), _result("") {};
    ~ShapeInfoVisitor() {};
    void visitCircle(Circle *circle);
    void visitRectangle(Rectangle *square);
    void visitTriangle(Triangle *triangle);
    void visitCompoundShape(CompoundShape *cs);
    std::string getResult() { return _result; };

private:
    std::string getIndent();

    std::string _result;
    int _indentLevel;
};

