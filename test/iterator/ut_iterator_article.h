#pragma once
#include <list>
#include "../../src/iterator/compound_iterator.h"
#include "../../src/paragraph.h"
#include "../../src/list_item.h"
#include "../../src/text.h"

#define CompoundArticleIterator CompoundIterator<std::list<Article*>::iterator>

class SuiteIterator : public ::testing::Test
{
protected:
    void SetUp() override
    {
        t = new Text("text");
        li = new ListItem("listItem")
        articles.push_back(t);
        articles.push_back(li);
    }

    void TearDown() override
    {
        for (Article* s : articles)
        {
            delete s;
        }
        articles.clear();
    }

    std::list<Article*> articles;
    Article* t;
    Article* li;
};

TEST_F(SuiteIterator, CompoundIteratorIsAIterator) {
    
    Iterator* it = new CompoundArticleIterator(articles.begin(), articles.end());
    ASSERT_EQ(typeid(CompoundArticleIterator), typeid(*it));
}

TEST_F(SuiteIterator, CompoundIteratorConstructShouldNoThrow) {
    ASSERT_NO_THROW(CompoundArticleIterator it(articles.begin(), articles.end()));
}

TEST_F(SuiteIterator, CompoundIteratorGetCurrentItemBeforeFirstShouldStillGetFirstItem) {
    CompoundArticleIterator it(articles.begin(), articles.end());
    ASSERT_EQ(t, it.currentItem());
}

TEST_F(SuiteIterator, CompoundIteratorShouldGetCorrectItemAfterNext) {
    CompoundArticleIterator it(articles.begin(), articles.end());
    
    ASSERT_EQ(t, it.currentItem());
    it.next();
    ASSERT_EQ(li, it.currentItem());
}

TEST_F(SuiteIterator, CompoundIteratorShouldGetFirstItemAfterCallFirst) {
    CompoundArticleIterator it(articles.begin(), articles.end());
    
    ASSERT_EQ(t, it.currentItem());
    it.next();
    ASSERT_EQ(li, it.currentItem());
    it.first();
    ASSERT_EQ(t, it.currentItem());
}

TEST_F(SuiteIterator, CompoundIteratorIsDoneShouldBeTrue) {
    CompoundArticleIterator it(articles.begin(), articles.end());
    
    ASSERT_EQ(t, it.currentItem());
    it.next();
    ASSERT_EQ(li, it.currentItem());
    it.next();
    ASSERT_TRUE(it.isDone());
}

TEST_F(SuiteIterator, CompoundIteratorNextShouldThrowExceptionWhileIsDone) {
    CompoundArticleIterator it(articles.begin(), articles.end());
    
    it.next();
    it.next();
    ASSERT_TRUE(it.isDone());
    ASSERT_ANY_THROW(it.next());
}

TEST_F(SuiteIterator, CompoundIteratorCurrentItemShouldThrowExceptionWhileIsDone) {
    CompoundArticleIterator it(articles.begin(), articles.end());
    
    it.next();
    it.next();
    ASSERT_TRUE(it.isDone());
    ASSERT_ANY_THROW(it.currentItem());
}

TEST_F(SuiteIterator, CompoundIteratorIsDone) {
    CompoundArticleIterator it(articles.begin(), articles.end());
    
    ASSERT_FALSE(it.isDone());
    ASSERT_NO_THROW(it.next());
    ASSERT_FALSE(it.isDone());
    ASSERT_NO_THROW(it.next());
    ASSERT_TRUE(it.isDone());
}
