.PHONY: clean test

all: directories ut_main

TEST= test/ut_paragraph.h test/ut_list_item.h test/ut_text.h test/ut_main.cpp \
	  test/ut_list_item.h test/iterator/ut_null_iterator.h \
	  test/iterator/ut_compound_iterator.h test/visitor/ut_markdown_visitor.h \
	  test/visitor/ut_html_visitor.h
SRC= src/article.h src/list_item.h src/paragraph.h src/text.h \
	 src/iterator/iterator.h src/iterator/compound_iterator.h \
	 src/iterator/null_iterator.h src/visitor/article_visitor.h \
	 src/visitor/html_visitor.h src/visitor/markdown_visitor.h

ut_main: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin

test: all
	bin/ut_all