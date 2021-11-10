#pragma once
#include "../src/paragraph.h"
#include "../src/list_item.h"
#include "../src/text.h"

class MarkdownVisitor : public ArticleVisitor
{
public:
    void visitListItem(ListItem *li) override {
        _result += li->getText();
    };

    void visitText(Text *t) override {
        _result += t->getText();
    }

    void visitParagraph(Paragraph *p) override {
        _result += li->getText();
    }

    std::string getResult() const override {}

private:
    std::string _result;
};