#pragma once
#include <list>
#include "article.h"
#include "visitor/article_visitor.h"
#include "iterator/compound_iterator.h"

#define CompoundArticleIterator CompoundIterator<std::list<Article*>::iterator>
class Paragraph : public Article
{
public:
    Paragraph(int level, std::string text) : _level(level), _text(text)
    {
        if (level < 1 || level > 6)
            throw std::invalid_argument(std::string("Level should >= 1 and <= 6"));
    }
    ~Paragraph()
    {
        for (Article *article : _articles)
        {
            delete article;
        }
        _articles.clear();
    }

    std::string getInfo() const override
    {
        std::string result = getPrefix() + _text + "\n";

        for (Article *article : _articles)
        {
            result += article->getText();
            if (article->getLevel() == 0 && article != _articles.back())
                result += "\n";
        }
        return result;
    }

    std::string getText() const override
    {
        return _text;
    }

    std::string getPrefix() const
    {
        std::string result = "";
        for (int i = 0; i < _level; i++)
        {
            result += "#";
        }
        return result + " ";
    }

    int getLevel() const override { return _level; }

    void add(Article *content) override
    {
        if (content->getLevel() != 0 && content->getLevel() <= _level)
            throw std::logic_error(std::string("Level of Paragraph added should greater than Paragraph."));
        _articles.push_back(content);
    }

    Iterator* createIterator() override { return new CompoundIterator<std::list<Article*>::iterator>(_articles.begin(),_articles.end()); }

    void accept(ArticleVisitor* visitor) override 
    {
        visitor->visitParagraph(this);
    }

private:
    int _level;
    std::string _text;
    std::list<Article*> _articles;
};