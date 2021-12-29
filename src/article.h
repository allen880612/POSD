#pragma once
#include <iostream>

class Iterator;
class ArticleVisitor;

class Article
{
public:
    virtual ~Article(){};
    virtual std::string getText() const = 0;
    virtual int getLevel() const { return 0; }
    virtual Iterator *createIterator() = 0;
    virtual void accept(ArticleVisitor *visitor) = 0;
    virtual void add(Article *article) { throw std::string("should not use this function"); };
    virtual void deleteArticle(Article *article) { throw std::string("should not use this function"); };
};