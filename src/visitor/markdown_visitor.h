#pragma once
#include "../paragraph.h"
#include "../list_item.h"
#include "../text.h"

class MarkdownVisitor : public ArticleVisitor
{
public:
    MarkdownVisitor() : _result("") {}
    void visitListItem(ListItem *li) override
    {
        _result += "- " + li->getText() + "\n";
    };

    void visitText(Text *t) override
    {
        _result += t->getText() + "\n";
    }

    void visitParagraph(Paragraph *p) override
    {

        _result += getPrefix(p->getLevel()) + p->getText() + "\n";
        Iterator *it = p->createIterator();
        while (!it->isDone())
        {
            it->currentItem()->accept(this);
            it->next();
        }
    }

    std::string getPrefix(int level) const
    {
        std::string result = "";
        for (int i = 0; i < level; i++)
        {
            result += "#";
        }
        return result + " ";
    }

    std::string getResult() const override { return _result; }

private:
    std::string _result = "";
};