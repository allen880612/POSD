#pragma once
#include <vector>
#include "article.h"

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

    std::string getText() const override
    {
        std::string result = _text;
        for (Article *article : _articles)
        {
            result += article->getText() + "\n";
        }
    }

    int getLevel() const override { return _level; }

    void add(Article *content) override
    {
        if (content->getLevel() > _level)
        {
            // std::cout << std::string(content->getText()) << std::endl;
            throw std::logic_error(std::string("Level of Paragraph added should greater than Paragraph."));
        }
        _articles.push_back(content);
    }

private:
    int _level;
    std::string _text;
    std::vector<Article* > _articles;
};