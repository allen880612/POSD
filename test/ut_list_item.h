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
    ASSERT_THROW(listItem->add(listItemAdded), std::logic_error);
}

TEST_F(SuiteListItem, GetLevelShouldBeZero) {
    ASSERT_EQ(0, listItem->getLevel());
}

TEST_F(SuiteListItem, GetText) {
    ASSERT_EQ(std::string("- content"), listItem->getText());
}