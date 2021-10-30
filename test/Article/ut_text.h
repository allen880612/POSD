#pragma once
#include "../src/text.h"

class SuiteText : public ::testing::Test
{
protected:
    void SetUp() override
    {
        text = new Text("content");
        textAdded = new Text("contentAdded");
    }

    void TearDown() override
    {
        delete text;
    }

    Article* text;
    Article* textAdded;
};

TEST_F(SuiteText, CheckType) {
    ASSERT_EQ(typeid(Text), typeid(*text));
}

TEST_F(SuiteText, AddOnTextShouldThrowException) {
    ASSERT_THROW(text->add(textAdded), std::logic_error);
}

TEST_F(SuiteText, GetLevelShouldBeZero) {
    ASSERT_EQ(0, text->getLevel());
}

TEST_F(SuiteText, GetText) {
    ASSERT_EQ(std::string("content"), text->getText());
}