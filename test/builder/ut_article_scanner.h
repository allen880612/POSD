#pragma once
#include "../../src/builder/article_scanner.h"

#define ACCURACY 0.001



TEST(CaseScanner, scanText) {
    std::string input = "Text (\"This is a text\")";
    ArticleScanner sc(input);

    ASSERT_EQ("Text", sc.nextToken());
    ASSERT_EQ("(", sc.nextToken());
    ASSERT_EQ("This is a text", sc.nextStr());
    ASSERT_EQ(")", sc.nextToken());
    ASSERT_TRUE(sc.isDone());
}

// TEST(CaseScanner, ScanIllegalWordShouldIgnore) {
//     std::string input = "I ListItem eee {\"string\"555\"next\"}too6a";
//     ArticleScanner sc(input);

//     ASSERT_EQ("ListItem", sc.nextToken());
//     ASSERT_EQ("string", sc.nextStr());
//     ASSERT_EQ("}", sc.nextToken());
//     ASSERT_EQ(6, sc.nextInt());
//     ASSERT_TRUE(sc.isDone());
// }

// TEST(CaseScanner, scanCircleWithNoise) {
//     std::string input = "I Circle eee ,tt{t3.14159a";
//     ArticleScanner sc(input);

//     ASSERT_EQ("Circle", sc.next());
//     ASSERT_EQ(",", sc.next());
//     ASSERT_EQ("{", sc.next());
//     ASSERT_NEAR(3.14159, sc.nextDouble(), ACCURACY);
//     ASSERT_TRUE(sc.isDone());
// }

TEST(CaseScanner, scanListItem) {
    std::string input = "ListItem (\"This is an list item\")";
    ArticleScanner sc(input);

    ASSERT_EQ("ListItem", sc.nextToken());
    ASSERT_EQ("(", sc.nextToken());
    ASSERT_EQ("This is an list item", sc.nextStr());
    ASSERT_EQ(")", sc.nextToken());
    ASSERT_TRUE(sc.isDone());
}

TEST(CaseScanner, scanEmptyParagraph) {
    std::string input = "Paragraph (1 \"This is an empty paragraph\") {}";
    ArticleScanner sc(input);

    ASSERT_EQ("Paragraph", sc.nextToken());
    ASSERT_EQ("(", sc.nextToken());
    ASSERT_EQ(1, sc.nextInt());
    ASSERT_EQ("This is an empty paragraph", sc.nextStr());
    ASSERT_EQ(")", sc.nextToken());
    ASSERT_EQ("{", sc.nextToken());
    ASSERT_EQ("}", sc.nextToken());
    ASSERT_TRUE(sc.isDone());
}

TEST(CaseScanner, scanSimpleParagraph) {
    std::string input = "Paragraph (1 \"This is a simple paragraph\") {\n"
                        "\tListItem (\"This is a list item\")\n"
                        "\tText (\"This is a text\")\n"
                        "}";
    ArticleScanner sc(input);

    ASSERT_EQ("Paragraph", sc.nextToken());
    ASSERT_EQ("(", sc.nextToken());
    ASSERT_EQ(1, sc.nextInt());
    ASSERT_EQ("This is a simple paragraph", sc.nextStr());
    ASSERT_EQ(")", sc.nextToken());
    ASSERT_EQ("{", sc.nextToken());
    ASSERT_EQ("ListItem", sc.nextToken());
    ASSERT_EQ("(", sc.nextToken());
    ASSERT_EQ("This is a list item", sc.nextStr());
    ASSERT_EQ(")", sc.nextToken());
    ASSERT_EQ("Text", sc.nextToken());
    ASSERT_EQ("(", sc.nextToken());
    ASSERT_EQ("This is a text", sc.nextStr());
    ASSERT_EQ(")", sc.nextToken());

    ASSERT_EQ("}", sc.nextToken());
    ASSERT_TRUE(sc.isDone());
}

TEST(CaseScanner, scanComplexParagraph) {
    std::string input = "Paragraph (1 \"This is a simple paragraph\") {\n"
                        "\tListItem (\"This is a list item\")\n"
                        "\tParagraph (2 \"This is an inner paragraph\") {\n"
                        "\t\tText (\"This is an inner text\")\n"
                        "\t\tListItem (\"This is an inner list item\")\n"
                        "\t}\n"
                        "Text (\"This is a text\")\n"
                        "}";
    ArticleScanner sc(input);

    ASSERT_EQ("Paragraph", sc.nextToken());
    ASSERT_EQ("(", sc.nextToken());
    ASSERT_EQ(1, sc.nextInt());
    ASSERT_EQ("This is a simple paragraph", sc.nextStr());
    ASSERT_EQ(")", sc.nextToken());
    ASSERT_EQ("{", sc.nextToken());
    
    ASSERT_EQ("ListItem", sc.nextToken());
    ASSERT_EQ("(", sc.nextToken());
    ASSERT_EQ("This is a list item", sc.nextStr());
    ASSERT_EQ(")", sc.nextToken());

    ASSERT_EQ("Paragraph", sc.nextToken());
    ASSERT_EQ("(", sc.nextToken());
    ASSERT_EQ(2, sc.nextInt());
    ASSERT_EQ("This is an inner paragraph", sc.nextStr());
    ASSERT_EQ(")", sc.nextToken());
    ASSERT_EQ("{", sc.nextToken());

    ASSERT_EQ("Text", sc.nextToken());
    ASSERT_EQ("(", sc.nextToken());
    ASSERT_EQ("This is an inner text", sc.nextStr());
    ASSERT_EQ(")", sc.nextToken());

    ASSERT_EQ("ListItem", sc.nextToken());
    ASSERT_EQ("(", sc.nextToken());
    ASSERT_EQ("This is an inner list item", sc.nextStr());
    ASSERT_EQ(")", sc.nextToken());
    ASSERT_EQ("}", sc.nextToken());

    ASSERT_EQ("Text", sc.nextToken());
    ASSERT_EQ("(", sc.nextToken());
    ASSERT_EQ("This is a text", sc.nextStr());
    ASSERT_EQ(")", sc.nextToken());

    ASSERT_EQ("}", sc.nextToken());
    ASSERT_TRUE(sc.isDone());
}

TEST(CaseScanner, callNextTokenShouldThrowExceptionWhileAlreadyDone) {
    std::string input = "";
    ArticleScanner sc(input);

    ASSERT_TRUE(sc.isDone());
    ASSERT_ANY_THROW(sc.nextToken());
}

TEST(CaseScanner, callNextIntShouldThrowExceptionWhileAlreadyDone) {
    std::string input = "";
    ArticleScanner sc(input);

    ASSERT_TRUE(sc.isDone());
    ASSERT_ANY_THROW(sc.nextInt());
}

TEST(CaseScanner, callNextStrShouldThrowExceptionWhileAlreadyDone) {
    std::string input = "";
    ArticleScanner sc(input);

    ASSERT_TRUE(sc.isDone());
    ASSERT_ANY_THROW(sc.nextStr());
}