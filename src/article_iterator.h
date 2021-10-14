#pragma once
#include "iterator.h"
#include "article.h"
#include <exception>

template<class ForwardIterator>
class ArticleIterator : public Iterator {
public:
    ShapeIterator(ForwardIterator begin, ForwardIterator end): _begin(begin), _end(end)
    {
        first();
    }
    
    void first() 
    {
        _current = _begin;
    }
    
    void next() {
        if(isDone())
            throw std::range_error(std::string("iterator is current end"));
        _current ++;
    }
    
    bool isDone() const 
    {
        return _current == _end;
    }
    
    Shape* currentItem() const 
    {
        return *_current;
    }
private:
  ForwardIterator _begin;
  ForwardIterator _end;
  ForwardIterator _current;
};