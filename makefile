.PHONY: clean test

SHAPE_TEST= test/ut_compound_shape.h test/ut_circle.h test/ut_rectangle.h \
			test/ut_triangle.h test/ut_two_dimensional_vector.h

ITERATOR_TEST= test/iterator/ut_null_iterator.h test/iterator/ut_compound_iterator.h

VISITOR_TEST= test/visitor/ut_shape_info_visitor.h test/visitor/ut_select_shape_visitor.h

BUILDER_TEST= test/builder/ut_shape_builder.h test/builder/ut_shape_parser.h \
			  test/builder/ut_scanner.h

SHAPE= src/shape.h src/rectangle.h src/circle.h src/triangle.h \
	   src/two_dimensional_vector.h src/compound_shape.h

ITERATOR= src/iterator/iterator.h src/iterator/null_iterator.h \
		  src/iterator/compound_iterator.h

VISITOR= src/visitor/shape_visitor.h src/visitor/shape_info_visitor.h \
		 src/visitor/select_shape_visitor.h

BUILDER= src/builder/shape_builder.h src/builder/shape_parser.h \
		 src/builder/scanner.h

SRC= $(SHAPE) $(ITERATOR) $(VISITOR) $(BUILDER)
TEST= $(SHAPE_TEST) $(ITERATOR_TEST) $(VISITOR_TEST) $(BUILDER_TEST)

# all: directories main ut_main

# main: src/main.cpp src/input_handler.h src/input_handler.cpp $(SRC)
# 	g++ -std=c++17 -Wfatal-errors src/input_handler.cpp src/main.cpp -o bin/main -lgtest -lpthread

all: directories ut_main

ut_main: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++17 -Wfatal-errors test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin
	
test: all
	bin/ut_all
