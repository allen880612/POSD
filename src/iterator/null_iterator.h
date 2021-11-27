#pragma once
#include <string>
#include "iterator.h"

class Shape;
class NullIterator : public Iterator
{
public:
    void first() override { throw std::string("Should not call this fuction"); }

    Shape* currentItem() const override { throw std::string("Should not call this fuction"); }

    void next() override { throw std::string("Should not call this fuction"); }

    bool isDone() const override { return true; }
};