.PHONY: clean test

all: directories ut_main

TEST= test/ut_paragraph.h test/ut_list_item.h test/ut_text.h \
	  test/iterator/ut_compound_iterator.h test/iterator/ut_null_iterator.h \
	  test/visitor/ut_markdown_visitor.h test/visitor/ut_html_visitor.h \
	  test/builder/ut_article_builder.h test/builder/ut_article_parser.h \
	  test/builder/ut_article_scanner.h

ARTICLE= src/article.h src/list_item.h src/paragraph.h src/text.h

ITERATOR= src/iterator/iterator.h src/iterator/compound_iterator.h \
	 	  src/iterator/null_iterator.h

VISITOR= src/visitor/article_visitor.h src/visitor/html_visitor.h \
		 src/visitor/markdown_visitor.h

BUILDER= src/builder/article_builder.h src/builder/article_parser.h \
		 src/builder/article_scanner.h

SRC= $(ARTICLE) $(ITERATOR) $(VISITOR) $(BUILDER)	  

ut_main: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin
	
test: all
	bin/ut_all