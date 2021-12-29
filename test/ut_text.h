#pragma once
#include "../src/text.h"
#include "../src/iterator/null_iterator.h"
#include "../src/visitor/markdown_visitor.h"

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
        delete textAdded;
    }

    Article* text;
    Article* textAdded;
};

TEST_F(SuiteText, CheckType) {
    ASSERT_EQ(typeid(Text), typeid(*text));
}

TEST_F(SuiteText, AddOnTextShouldThrowException) {
    ASSERT_ANY_THROW(text->add(textAdded));
}

TEST_F(SuiteText, GetLevelShouldBeZero) {
    ASSERT_EQ(0, text->getLevel());
}

TEST_F(SuiteText, GetText) {
    ASSERT_EQ(std::string("content"), text->getText());
}

TEST_F(SuiteText, CreateIteratorShouldBeNulliterator) {
    Iterator* it = text->createIterator();
    ASSERT_EQ(typeid(NullIterator), typeid(*it));
    delete it;
}

TEST_F(SuiteText, IteratorIsdoneShouldBeTrue) {
    Iterator* it = text->createIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}