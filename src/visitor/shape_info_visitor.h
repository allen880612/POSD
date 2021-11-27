#pragma once

#include <string>

#include "../circle.h"
#include "../compound_shape.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "./shape_visitor.h"

class ShapeInfoVisitor : public ShapeVisitor {
   public:
    void visitCircle(Circle* circle) {}
    void visitRectangle(Rectangle* rectangle) {}
    void visitTriangle(Triangle* triangle) {}
    void visitCompoundShape(CompoundShape* compoundShape) {}
    std::string getResult() {}

   private:
    int depth = 0;
    std::string result = "";
};

