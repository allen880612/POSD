#pragma once
#include <gtest/gtest.h>
#include <list>
#include "../src/iterator/null_iterator.h"
#include "../src/iterator/compound_iterator.h"
#include "../src/circle.h"
#include "../src/rectangle.h"

#define CompoundShapeIterator CompoundIterator<std::list<Shape*>::iterator>

class SuiteIterator : public ::testing::Test
{
protected:
    void SetUp() override
    {
        nullIterator = new NullIterator();
        c1 = new Circle(1.0);
        r45 = new Rectangle(4.0, 5.0);
        shapes.push_back(c1);
        shapes.push_back(r45);
    }

    void TearDown() override
    {
        delete nullIterator;
        for (Shape* s : shapes)
        {
            delete s;
        }
        shapes.clear();
    }

    Iterator* nullIterator;
    std::list<Shape*> shapes;
    Shape* c1;
    Shape* r45;
};

TEST_F(SuiteIterator, NullIteratorCallFirstShouldThrowException) {
    ASSERT_ANY_THROW(nullIterator->first());
}

TEST_F(SuiteIterator, NullIteratorCallCurrentItemShouldThrowException) {
    ASSERT_ANY_THROW(nullIterator->currentItem());
}

TEST_F(SuiteIterator, NullIteratorCallNextShouldThrowException) {
    ASSERT_ANY_THROW(nullIterator->next());
}

TEST_F(SuiteIterator, NullIteratorCallIsDoneShouldBeTrue) {
    ASSERT_TRUE(nullIterator->isDone());
}

TEST_F(SuiteIterator, CompoundIteratorConstructShouldNoThrow) {
    ASSERT_NO_THROW(CompoundShapeIterator it(shapes.begin(), shapes.end()));
}

TEST_F(SuiteIterator, CompoundIteratorGetCurrentItemBeforeFirstShouldStillGetFirstItem) {
    CompoundShapeIterator it(shapes.begin(), shapes.end());
    ASSERT_EQ(c1, it.currentItem());
}

TEST_F(SuiteIterator, CompoundIteratorShouldGetCorrectItemAfterNext) {
    CompoundShapeIterator it(shapes.begin(), shapes.end());
    
    ASSERT_EQ(c1, it.currentItem());
    it.next();
    ASSERT_EQ(r45, it.currentItem());
}

TEST_F(SuiteIterator, CompoundIteratorShouldGetFirstItemAfterCallFirst) {
    CompoundShapeIterator it(shapes.begin(), shapes.end());
    
    ASSERT_EQ(c1, it.currentItem());
    it.next();
    ASSERT_EQ(r45, it.currentItem());
    it.first();
    ASSERT_EQ(c1, it.currentItem());
}

TEST_F(SuiteIterator, CompoundIteratorIsDoneShouldBeTrue) {
    CompoundShapeIterator it(shapes.begin(), shapes.end());
    
    ASSERT_EQ(c1, it.currentItem());
    it.next();
    ASSERT_EQ(r45, it.currentItem());
    it.next();
    ASSERT_TRUE(it.isDone());
}

TEST_F(SuiteIterator, CompoundIteratorNextShouldThrowExceptionWhileIsDone) {
    CompoundShapeIterator it(shapes.begin(), shapes.end());
    
    it.next();
    it.next();
    ASSERT_TRUE(it.isDone());
    ASSERT_ANY_THROW(it.next());
}

TEST_F(SuiteIterator, CompoundIteratorIsDoneShouldBeFalseBeforeCurrentNotTheLastElement) {
    CompoundShapeIterator it(shapes.begin(), shapes.end());
    
    ASSERT_FALSE(it.isDone());
    it.next();
    ASSERT_FALSE(it.isDone());
    it.next();
    ASSERT_TRUE(it.isDone());
    ASSERT_EQ(*(shapes.end()), it.currentItem());
}

        