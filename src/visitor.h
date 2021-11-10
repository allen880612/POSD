#pragma once

class Article;
class Paragraph;
class ListItem;
class Text;

class Visitor
{
public:
    virtual ~Visitor() {}
    virtual void visitArticle(Article* a) = 0;
    virtual void visitParagraph(Paragraph *p) = 0;
    virtual void visitListItem(ListItem *item) = 0;
    virtual void visitText(Text* t) = 0;
protected:
    Visitor() {}
};