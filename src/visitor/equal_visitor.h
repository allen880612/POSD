#pragma once
#include "../paragraph.h"
#include "../list_item.h"
#include "../text.h"

class EqualVisitor : public ArticleVisitor
{
public:
    EqualVisitor() : _compare(nullptr), _isEqual(true) {}
    EqualVisitor(Article* compare) : _compare(compare), _isEqual(true) {}

    void visitListItem(ListItem *li) override
    {
        _isEqual &= _compare->getText() == li->getText();
    };

    void visitText(Text *t) override
    {
        _isEqual &= _compare->getText() == t->getText();
    }

    void visitParagraph(Paragraph *p) override
    {
        _isEqual &= _compare->getText() == p->getText() && _compare->getLevel() == p->getLevel();

        Iterator *it = p->createIterator();
        Iterator *compareIt = _compare->createIterator();

        std::string paragraphText = "";
        std::string compareParagraphText = "";

        while (!it->isDone())
        {
            paragraphText += it->currentItem()->getText();
            it->next();
        }

        while (!compareIt->isDone())
        {
            compareParagraphText += compareIt->currentItem()->getText();
            compareIt->next();
        }

        _isEqual &= paragraphText == compareParagraphText;
        
        delete it;
        delete compareIt;
    }

    std::string getResult() const override { return _result; }

    std::string isEqual() const override { return _isEqual; }

private:
    std::string _result = "";
    bool _isEqual = true;
    Article* _compare;
};