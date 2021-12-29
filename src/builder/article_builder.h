#pragma once
#include "../article.h"
#include "../paragraph.h"
#include "../text.h"
#include "../list_item.h"
#include <stack>
#include <list>

class ArticleBuilder {
public:
    static ArticleBuilder* getInstance() {
        // local static parameter only initialize 
        // when first time call static function
        static ArticleBuilder instance;
        return &instance;
    }
    void reset();
    ~ArticleBuilder() { reset(); }

    void buildText(std::string text);
    void buildListItem(std::string text);
    void buildParagraphBegin(int level, std::string text);
    void buildParagraphEnd();
    Article* getArticle();

private:
    ArticleBuilder() {};
    bool topIsNonEmptyCompoundArticle();
    std::stack<Article*> _articles;
};

void ArticleBuilder::reset() {
    while (!_articles.empty()) {
        Article* deleteArticle = _articles.top();
        _articles.pop();
        delete deleteArticle;
    }
}

void ArticleBuilder::buildText(std::string text) {
    _articles.push(new Text(text));
}

void ArticleBuilder::buildListItem(std::string text) {
    _articles.push(new ListItem(text));
}

void ArticleBuilder::buildParagraphBegin(int level, std::string text) {
    _articles.push(new Paragraph(level, text));
}

bool ArticleBuilder::topIsNonEmptyCompoundArticle() {
    Article* top = _articles.top();
    bool isCompoundArticle = typeid(*top) == typeid(Paragraph);
    Iterator* it = top->createIterator();
    bool isNonEmptyCompoundArticle = isCompoundArticle && !it->isDone();
    delete it;
    return !isCompoundArticle || isNonEmptyCompoundArticle;
}

void ArticleBuilder::buildParagraphEnd() {
    std::list<Article*> components;
    while(topIsNonEmptyCompoundArticle()) {
        components.push_back(_articles.top());
        _articles.pop();
    }
    Article* compound = _articles.top();
    for(auto it = components.rbegin() ; it != components.rend() ; it++){
        compound->add(*it);
    }
}

Article* ArticleBuilder::getArticle(){
    if (_articles.empty()) {
        throw std::string("Should call build some shape BEFORE call getShape()!");
    }
    Article* result = _articles.top();
    _articles.pop();
    return result;
}