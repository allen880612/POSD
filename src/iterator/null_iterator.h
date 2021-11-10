#pragma once
#include <string>
#include "iterator.h"

class Article;

class NullIterator : public Iterator
{
public:
    void first() override { throw std::string("Should not call this fuction"); }

    Article *currentItem() const override { throw std::string("Should not call this fuction"); }

    void next() override { throw std::string("Should not call this fuction"); }

    bool isDone() const override { return true; }
};