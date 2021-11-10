#pragma once
#include "../src/list_item.h"

class SuiteListItem : public ::testing::Test
{
protected:
    void SetUp() override
    {
        listItem = new ListItem("content");
        listItemAdded = new ListItem("contentAdded");
    }

    void TearDown() override
    {
        delete listItem;
        delete listItemAdded;
    }

    Article* listItem;
    Article* listItemAdded;
};

TEST_F(SuiteListItem, CheckType) {
    ASSERT_EQ(typeid(ListItem), typeid(*listItem));
}

TEST_F(SuiteListItem, AddOnTextShouldThrowException) {
    ASSERT_ANY_THROW(listItem->add(listItemAdded));
}

TEST_F(SuiteListItem, GetLevelShouldBeZero) {
    ASSERT_EQ(0, listItem->getLevel());
}

TEST_F(SuiteListItem, GetText) {
    ASSERT_EQ(std::string("- content"), listItem->getText());
}

TEST_F(SuiteListItem, CreateIteratorShouldBeNulliterator) {
    Iterator* it = listItem->createIterator();
    ASSERT_EQ(typeid(NullIterator), typeid(*it));
    delete it;
}

TEST_F(SuiteListItem, IteratorIsdoneShouldBeTrue) {
    Iterator* it = listItem->createIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}