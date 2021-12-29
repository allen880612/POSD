
#pragma once
#include "../../src/iterator/null_iterator.h"

class SuiteNullIteratort : public ::testing::Test
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

TEST_F(SuiteNullIteratort, NullIteratorIsAIterator) {
    ASSERT_EQ(typeid(NullIterator), typeid(*nullIterator));
}

TEST_F(SuiteNullIteratort, NullIteratorCallFirstShouldThrowException) {
    ASSERT_ANY_THROW(nullIterator->first());
}

TEST_F(SuiteNullIteratort, NullIteratorCallCurrentItemShouldThrowException) {
    ASSERT_ANY_THROW(nullIterator->currentItem());
}

TEST_F(SuiteNullIteratort, NullIteratorCallNextShouldThrowException) {
    ASSERT_ANY_THROW(nullIterator->next());
}

TEST_F(SuiteNullIteratort, NullIteratorCallIsDoneShouldBeTrue) {
    ASSERT_TRUE(nullIterator->isDone());
}