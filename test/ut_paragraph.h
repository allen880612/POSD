#pragma once
#include "../src/paragraph.h"
#include "../src/list_item.h"
#include "../src/text.h"
#include "../src/iterator/compound_iterator.h"

class SuiteParagraph : public ::testing::Test
{
protected:
    void SetUp() override
    {
        p1 = new Paragraph(1, "title");
        p2 = new Paragraph(2, "title2");
        p3 = new Paragraph(3, "title3");
        p3_2 = new Paragraph(3, "sameLevel");
        t1 = new Text("text");
        t2 = new Text("sub text");
        for (int i=1; i<=4; i++)
        {
            std::string itemText = std::string("list") + std::to_string(i);
            listItems.push_back(new ListItem(itemText));
        }

        p1->add(listItems[0]);
        p1->add(listItems[1]);
        p1->add(t1);
        p2->add(listItems[2]);
        p2->add(listItems[3]);
        p2->add(t2);
        p1->add(p2);
    }

    void TearDown() override
    {
        delete p1;
        delete p3;
        delete p3_2;
        listItems.clear();
    }

    Article* p1;
    Article* p2;
    Article* p3;
    Article* p3_2;
    Article* t1;
    Article* t2;
    std::vector<Article*> listItems;
};

TEST_F(SuiteParagraph, CheckType) {
    ASSERT_EQ(typeid(Paragraph), typeid(*p1));
}

TEST_F(SuiteParagraph, GetLevel) {
    ASSERT_EQ(1, p1->getLevel());
    ASSERT_EQ(2, p2->getLevel());
    ASSERT_EQ(3, p3->getLevel());
}

TEST_F(SuiteParagraph, AddLowerLevelShouldThrowException) {
    ASSERT_THROW(p3->add(p1), std::logic_error);
}

TEST_F(SuiteParagraph, AddSameLevelShouldThrowException) {
    ASSERT_THROW(p3->add(p3_2), std::logic_error);
}

TEST_F(SuiteParagraph, ConstructWithNagativeLevelShouldThrowException) {
    ASSERT_THROW(Paragraph p(-1, ""), std::invalid_argument);
}

TEST_F(SuiteParagraph, ConstructWithLevelZeroShouldThrowException) {
    ASSERT_THROW(Paragraph p(0, ""), std::invalid_argument);
}

TEST_F(SuiteParagraph, ConstructWithLevelGratherThanSixShouldThrowException) {
    ASSERT_THROW(Paragraph p(7, ""), std::invalid_argument);
}

TEST_F(SuiteParagraph, getText) {
    std::string expected = "### title3\n";
    ASSERT_EQ(expected, p3->getText());
}

TEST_F(SuiteParagraph, getTextShouldContainChildenContent) {
    std::string expected = "# title\n- list1\n- list2\ntext\n## title2\n- list3\n- list4\nsub text";
    ASSERT_EQ(expected, p1->getText());
}

TEST_F(SuiteParagraph, iteratorShouldContainCorrectItem) {
    Iterator* it = p1->createIterator();

    it->first();
    ASSERT_EQ(listItems[0], it->currentItem());
    it->next();
    ASSERT_EQ(listItems[1], it->currentItem());
    it->next();
    ASSERT_EQ(t1, it->currentItem());
    it->next();
    ASSERT_EQ(p2, it->currentItem());
    it->next();
    ASSERT_TRUE(it->isDone());
    delete it;
}