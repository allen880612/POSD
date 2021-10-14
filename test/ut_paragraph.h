#pragma once
#include "../src/paragraph.h"
#include "../src/list_item.h"
#include "../src/text.h"
#include <string>

class SuiteParagraph : public ::testing::Test
{
protected:
    void SetUp() override
    {
        p1 = new Paragraph(1, "title");
        p2 = new Paragraph(2, "title2");
        p3 = new Paragraph(3, "title3");
        t1 = new Text("text");
        t2 = new Text("sub text");
        
        for (int i=1; i<=4; i++)
        {
            std::string itemText = std::string("item") + std::to_string(i);
            listItems.push_back(new ListItem(itemText));
        }

        p1->add(listItems[0]);
        p1->add(listItems[1]);
        p2->add(listItems[2]);
        p2->add(listItems[3]);
        p1->add(p2);
    }

    void TearDown() override
    {
        delete p1;
        listItems.clear();
    }

    Article* p1;
    Article* p2;
    Article* p3;
    Article* t1;
    Article* t2;
    std::vector<Article*> listItems;
};

TEST_F(SuiteParagraph, CheckType) {
    ASSERT_EQ(typeid(Paragraph), typeid(*p1));
}

TEST_F(SuiteParagraph, AddLowerLevelShouldThrowException) {
    ASSERT_THROW(p3->add(p1), std::logic_error);
}

// TEST_F(SuiteParagraph, ConstructWithNagativeLevelShouldThrowException) {
//     ASSERT_THROW(Paragraph p(-1, ""), std::invalid_argument);
// }

// TEST_F(SuiteParagraph, ConstructWithZeroLevelShouldThrowException) {
//     ASSERT_THROW(Paragraph p(0, ""), std::invalid_argument);
// }

// TEST_F(SuiteParagraph, ConstructWithLevelGratherThanSixShouldThrowException) {
//     ASSERT_THROW(Paragraph p(7, ""), std::invalid_argument);
// }

// TEST_F(SuiteParagraph, getTextShouldContainChildenContent) {
//     std::string expected = "# title\n- list1\n- list2\ntext\n## title2\n- list3\n- list4\nsub text";
//     ASSERT_EQ(expected, p1->getText());
// }