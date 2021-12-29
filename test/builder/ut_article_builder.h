#pragma once
#include "../../src/builder/article_builder.h"

#include <cmath>
#define ACCURACY 0.001

class CaseArticleBuilder : public ::testing::Test
{
protected:
    void SetUp() override
    {
        builder = ArticleBuilder::getInstance();
    }

    void TearDown() override
    {

    }

    ArticleBuilder* builder;

};

TEST_F(CaseArticleBuilder, buildText) {
    std::string expected = "Text";

    builder->buildText(expected);
    Article* article = builder->getArticle();

    ASSERT_EQ(typeid(Text), typeid(*article));
    ASSERT_EQ(expected, article->getText());
    delete article;
}

TEST_F(CaseArticleBuilder, buildListItem) {
    std::string expected = "ListItem";

    builder->buildListItem("ListItem");
    Article* article = builder->getArticle();

    ASSERT_EQ(typeid(ListItem), typeid(*article));
    ASSERT_EQ(expected, article->getText());
    delete article;
}

TEST_F(CaseArticleBuilder, buildEmptyParagraph) {
    int level = 1;
    std::string expected = "Paragraph";

    builder->buildParagraphBegin(1, expected);
    builder->buildParagraphEnd();
    Article* article = builder->getArticle();

    ASSERT_EQ(typeid(Paragraph), typeid(*article));
    ASSERT_EQ(level, article->getLevel());
    ASSERT_EQ(expected, article->getText());
    delete article;
}

TEST_F(CaseArticleBuilder, buildSimpleCompoundShape) {

    builder->buildParagraphBegin(1, "Paragraph");
    builder->buildText("Text");
    builder->buildListItem("ListItem");
    builder->buildParagraphEnd();
    Article* article = builder->getArticle();
    
    ASSERT_EQ(typeid(Paragraph), typeid(*article));
    ASSERT_EQ(1, article->getLevel());
    ASSERT_EQ("Paragraph", article->getText());

    Iterator* it = article->createIterator();
    Article* text = it->currentItem();
    ASSERT_EQ(typeid(Text), typeid(*text));
    ASSERT_EQ("Text", text->getText());

    it->next();
    Article* listItem = it->currentItem();
    ASSERT_EQ(typeid(ListItem), typeid(*listItem));
    ASSERT_EQ("ListItem", listItem->getText());
    
    it->next();
    ASSERT_TRUE(it->isDone());

    delete it;
    delete article;
}

TEST_F(CaseArticleBuilder, buildComplexCompoundShape) {
    builder->buildParagraphBegin(1, "Paragraph");
    builder->buildText("Text");
    builder->buildListItem("ListItem");
    builder->buildParagraphBegin(2, "Inner Paragraph");
    builder->buildText("Inner Text");
    builder->buildListItem("Inner ListItem");
    builder->buildParagraphEnd();
    builder->buildParagraphEnd();
    Article* article = builder->getArticle();
    
    ASSERT_EQ(typeid(Paragraph), typeid(*article));
    ASSERT_EQ(1, article->getLevel());
    ASSERT_EQ("Paragraph", article->getText());

    Iterator* it = article->createIterator();
    Article* text = it->currentItem();
    ASSERT_EQ(typeid(Text), typeid(*text));
    ASSERT_EQ("Text", text->getText());

    it->next();
    Article* listItem = it->currentItem();
    ASSERT_EQ(typeid(ListItem), typeid(*listItem));
    ASSERT_EQ("ListItem", listItem->getText());

    it->next();
    Article* innerParagraph = it->currentItem();
    ASSERT_EQ(typeid(Paragraph), typeid(*innerParagraph));
    ASSERT_EQ("Inner Paragraph", innerParagraph->getText());
    
    it->next();
    ASSERT_TRUE(it->isDone());

    Iterator* innerIt = innerParagraph->createIterator();
    Article* innerText = innerIt->currentItem();
    ASSERT_EQ(typeid(Text), typeid(*innerText));
    ASSERT_EQ("Inner Text", innerText->getText());

    innerIt->next();
    Article* innerListItem = innerIt->currentItem();
    ASSERT_EQ(typeid(ListItem), typeid(*innerListItem));
    ASSERT_EQ("Inner ListItem", innerListItem->getText());

    innerIt->next();
    ASSERT_TRUE(innerIt->isDone());

    delete it;
    delete innerIt;
    delete article;
}

TEST_F(CaseArticleBuilder, builderShouldBeSingleton) {
    ArticleBuilder* builder1 = ArticleBuilder::getInstance();
    ArticleBuilder* builder2 = ArticleBuilder::getInstance();
    ASSERT_EQ(builder1, builder2);

}