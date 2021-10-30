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
        std::string result = getPrefix() + _text + "\n";

        for (Article *article : _articles)
        {
            result += article->getText();
            if (article->getLevel() == 0 && article != _articles.back())
                result += "\n";
        }
        return result;
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

private:
    int _level;
    std::string _text;
    std::vector<Article* > _articles;
};