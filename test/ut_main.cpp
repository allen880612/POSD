#include <gtest/gtest.h>

#include "./iterator/ut_compound_iterator.h"
#include "./iterator/ut_null_iterator.h"
#include "./ut_list_item.h"
#include "./ut_paragraph.h"
#include "./ut_text.h"
// #include "./visitor/ut_html_visitor.h"
#include "./visitor/ut_markdown_visitor.h"


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
