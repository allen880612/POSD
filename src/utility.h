#pragma once
#include "iterator/iterator.h"
#include "shape.h"

template<class ShapeConstraint>
Shape* selectShape(Shape* shape, ShapeConstraint constraint) 
{ 
    Iterator* it = shape->createIterator();
    Shape* result = nullptr;

    while (!it->isDone())
    {   
        Shape* current = it->currentItem();
        // std::cout << current->info() << std::endl;

        if (constraint(current))
        {
            result = current;
            break;
        }
        
        it->next();
    }

    delete it;
    return result;
}