#pragma once

class Paragraph;
class ListItem;
class Text;

class ArticleVisitor {
   public:
    virtual void visitListItem(ListItem* li) = 0;
    virtual void visitText(Text* t) = 0;
    virtual void visitParagraph(Paragraph* p) = 0;
    virtual std::string getResult() const = 0;

   protected:
    ArticleVisitor() {}
};