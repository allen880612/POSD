#pragma once
#include "article.h"

class Text : public Article
{
public:
    Text(std::string text) : _text(text) {}
    std::string getText() const override { return _text; }

private:
    std::string _text;
};