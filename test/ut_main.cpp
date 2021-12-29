#include <gtest/gtest.h>

#include "./ut_list_item.h"
#include "./ut_text.h"
#include "./ut_paragraph.h"

#include "./iterator/ut_compound_iterator.h"
#include "./iterator/ut_null_iterator.h"

#include "./visitor/ut_html_visitor.h"
#include "./visitor/ut_markdown_visitor.h"

#include "./builder/ut_article_builder.h"
#include "./builder/ut_article_scanner.h"
#include "./builder/ut_article_parser.h"


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
