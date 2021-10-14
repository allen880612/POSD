#pragma once
#include <iostream>
#include <exception>

class Article
{
public:
    virtual ~Article(){};
    virtual std::string getText() const = 0;
    virtual int getLevel() const { return 0; }
    // virtual int createIterator() const {} 
    virtual void add(Article *dpFormat) { throw std::logic_error(std::string("Not Implement!")); };
    // virtual void remove(Article *dpFormat) {throw std::logic_error("Not Implement!"); };
};