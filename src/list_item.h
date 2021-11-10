#pragma once
#include "article.h"
#include "visitor/article_visitor.h"
#include "iterator/null_iterator.h"

class ListItem : public Article
{
public:
    ListItem(std::string text) : _text(text) {}
    std::string getText() const override { return "- " + _text; }
    Iterator* createIterator() override { return new NullIterator(); }
    void accept(ArticleVisitor* visitor) override 
    {
        visitor->visitListItem(this);
    }
private:
    std::string _text;
};