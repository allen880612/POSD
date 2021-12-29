.PHONY: clean test

TEST_ARTICLE= test/ut_paragraph.h test/ut_list_item.h test/ut_text.h

TEST_ITERATOR= test/iterator/ut_null_iterator.h test/iterator/ut_compound_iterator.h \
	  
TEST_VISITOR= test/visitor/ut_markdown_visitor.h test/visitor/ut_html_visitor.h

TEST_BUILDER= test/builder/ut_article_builder.h


ARTILCE= src/article.h src/list_item.h src/paragraph.h src/text.h

ITERATOR= src/iterator/iterator.h src/iterator/null_iterator.h \
		  src/iterator/compound_iterator.h

VISITOR= src/visitor/article_visitor.h src/visitor/html_visitor.h

BUILDER= src/builder/article_builder.h

SRC= $(ARTICLE) $(ITERATOR) $(VISITOR) $(BUILDER)

TEST= $(TEST_ARTICLE) $(TEST_ITERATOR) $(TEST_VISITOR) $(TEST_BUILDER)

all: directories ut_main

ut_main: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++17 -Wfatal-errors test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin
	
test: all
	bin/ut_all
