#pragma once
#include "../../src/builder/article_parser.h"
#include "../../src/article.h"
#include <cmath>

#define ACCURACY 0.001

TEST(CaseParser, parseText) {
    std::string path = "test/data/text.txt";
    ArticleParser parser(path);
    Article* article = nullptr;
    
    parser.parse();
    article = parser.getArticle();

    ASSERT_EQ(typeid(Text), typeid(*article));
    ASSERT_EQ("This is a text", article->getText());
    delete article;
}

TEST(CaseParser, parseListItem) {
    std::string path = "test/data/list_item.txt";
    ArticleParser parser(path);
    Article* article = nullptr;
    
    parser.parse();
    article = parser.getArticle();

    ASSERT_EQ(typeid(ListItem), typeid(*article));
    ASSERT_EQ("This is a list item", article->getText());
    delete article;
}

TEST(CaseParser, parseEmptyParagraph) {
    std::string path = "test/data/empty_paragraph.txt";
    ArticleParser parser(path);
    Article* article = nullptr;
    
    parser.parse();
    article = parser.getArticle();

    ASSERT_EQ(typeid(Paragraph), typeid(*article));
    ASSERT_EQ(1, article->getLevel());
    ASSERT_EQ("This is an empty paragraph", article->getText());
    delete article;
}

TEST(CaseParser, parseSimpleParagraph) {
    std::string path = "test/data/simple_paragraph.txt";
    ArticleParser parser(path);
    Article* article = nullptr;
    
    parser.parse();
    article = parser.getArticle();

    ASSERT_EQ(typeid(Paragraph), typeid(*article));
    ASSERT_EQ("This is a simple paragraph", article->getText());
    ASSERT_EQ(1, article->getLevel());

    Iterator* it = article->createIterator();
    Article* listItem = it->currentItem();
    ASSERT_EQ(typeid(ListItem), typeid(*listItem));
    ASSERT_EQ("This is a list item", listItem->getText());

    it->next();
    Article* text = it->currentItem();
    ASSERT_EQ(typeid(Text), typeid(*text));
    ASSERT_EQ("This is a text", text->getText());

    it->next();
    ASSERT_TRUE(it->isDone());
    delete it;
    delete article;
}

TEST(CaseParser, parseComplexParagraph) {
    std::string path = "test/data/complex_paragraph.txt";
    ArticleParser parser(path);
    Article* article = nullptr;
    
    parser.parse();
    article = parser.getArticle();

    ASSERT_EQ(typeid(Paragraph), typeid(*article));
    ASSERT_EQ("This is a complex paragraph", article->getText());
    ASSERT_EQ(1, article->getLevel());

    Iterator* it = article->createIterator();
    Article* listItem = it->currentItem();
    ASSERT_EQ(typeid(ListItem), typeid(*listItem));
    ASSERT_EQ("This is a list item", listItem->getText());

    it->next();
    Article* innerParagraph = it->currentItem();
    ASSERT_EQ(typeid(Paragraph), typeid(*innerParagraph));
    ASSERT_EQ("This is an inner paragraph", innerParagraph->getText());
    ASSERT_EQ(2, innerParagraph->getLevel());

    it->next();
    Article* text = it->currentItem();
    ASSERT_EQ(typeid(Text), typeid(*text));
    ASSERT_EQ("This is a text", text->getText());

    it->next();
    ASSERT_TRUE(it->isDone());

    Iterator* innerIt = innerParagraph->createIterator();
    Article* innerText = innerIt->currentItem();
    ASSERT_EQ(typeid(Text), typeid(*innerText));
    ASSERT_EQ("This is an inner text", innerText->getText());

    innerIt->next();
    Article* innerListItem = innerIt->currentItem();
    ASSERT_EQ(typeid(ListItem), typeid(*innerListItem));
    ASSERT_EQ("This is an inner list item", innerListItem->getText());

    innerIt->next();
    ASSERT_TRUE(innerIt->isDone());

    delete it;
    delete innerIt;
    delete article;
}


TEST(CaseParser, parseNotExistFileShouldThrowException) {
    std::string path = "NOT_EXIT_FILE";
    ASSERT_ANY_THROW(ArticleParser parser(path));
}