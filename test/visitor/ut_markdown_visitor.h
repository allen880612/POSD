#pragma once
#include "../src/paragraph.h"
#include "../src/list_item.h"
#include "../src/text.h"
#include "../src/iterator/compound_iterator.h"
#include "../src/visitor/markdown_visitor.h"

class SuiteMarkdownVisitor : public ::testing::Test
{
protected:
    void SetUp() override
    {
        visitor = new MarkdownVisitor();
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
        delete visitor;
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
    std::list<Article*> listItems;
    MarkdownVisitor* visitor;
};

TEST_F(SuiteParagraph, getText) {
    std::string expected = "### title3\n";
    visitor->visitParagraph
    ASSERT_EQ(expected, p3->getText());
}

TEST_F(SuiteParagraph, getTextShouldContainChildenContent) {
    std::string expected = "# title\n- list1\n- list2\ntext\n## title2\n- list3\n- list4\nsub text";
    ASSERT_EQ(expected, p1->getText());
}



