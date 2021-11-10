#pragma once
#include "../paragraph.h"
#include "../list_item.h"
#include "../text.h"

class HtmlVisitor : public ArticleVisitor
{
public:
    void visitListItem(ListItem *li) override
    {
        _result += "<li>" + li->getText() + "</li>";
    };

    void visitText(Text *t) override
    {
        _result += "<span>" + t->getText() + "</span>";
    };

    void visitParagraph(Paragraph *p) override
    {
        _result += "<div><h" + std::to_string(p->getLevel()) + ">" + p->getText() + "</h" + std::to_string(p->getLevel()) + ">";
        Iterator *it = p->createIterator();
        while (!it->isDone())
        {
            it->currentItem()->accept(this);
            it->next();
        }
        _result += + "</div>";
    };

    std::string getResult() const override { return _result; }
    std::string getHtml(std::string tag, std::string content)
    { 
        char buffer[1000];
        sprintf(buffer, "<%s>%s</%s>", tag, content, tag);
        return buffer;
    }
private:
    std::string _result = "";
};