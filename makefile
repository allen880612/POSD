.PHONY: clean test

TEST= test/ut_compound_shape.h test/ut_circle.h test/ut_rectangle.h \
	  test/ut_triangle.h test/ut_two_dimensional_vector.h \
	  test/iterator/ut_null_iterator.h test/iterator/ut_compound_iterator.h \
	  test/visitor/ut_shape_info_visitor.h

SHAPE= src/shape.h src/rectangle.h src/circle.h src/triangle.h \
	   src/two_dimensional_vector.h src/compound_shape.h

ITERATOR= src/iterator/iterator.h src/iterator/null_iterator.h \
		  src/iterator/compound_iterator.h

VISITOR= src/visitor/shape_visitor.h src/visitor/shape_info_visitor.h

SRC= $(SHAPE) $(ITERATOR) $(VISITOR)

all: directories ut_main

ut_main: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++11 -Wfatal-errors test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin
	
test: all
	bin/ut_all