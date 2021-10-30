#pragma once
#include <gtest/gtest.h>
#include "../src/iterator/null_iterator.h"

class SuiteIterator : public ::testing::Test
{
protected:
    void SetUp() override
    {
        nullIterator = new NullIterator();
    }

    void TearDown() override
    {
        delete nullIterator;
    }

    Iterator* nullIterator;
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