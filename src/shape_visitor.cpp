#include "./shape_visitor.h"
#include "./circle.h"
#include "./compound_shape.h"

void SelectShapeVisitor::visitCircle(Circle* c) {
    if (_constraint) {
        if (_constraint(c)) {
            _result = c; 
        }
    }
}

// void SelectShapeVisitor::visitSquare(Square* s) {
//     if (_constraint) {
//         if (_constraint(s)) {
//             _result = s; 
//         }
//     }
// }

// void SelectShapeVisitor::visitCompoundShape(CompoundShape* cs) {
//     Iterator* it = cs->createIterator();
//     for (it->first(); !it->isDone(); it->next()) {
//         it->currentItem()->accept(this);
//     }
// }

Shape* SelectShapeVisitor::getShape() {
    return _result;
}