.PHONY: clean test

all: directories obj/shape_visitor.o ut_main

TEST: test/ut_rectangle.h test/ut_circle.h test/ut_triangle.h \
	  test/ut_two_dimensional_vector.h test/compound_shape.h test/iterator.h \
	  test/ut_utility.h test/ut_visitor.h

SHAPE: src/shape.h src/rectangle.h src/circle.h src/triangle.h \
	   src/two_dimensional_vector.h src/compound_shape.h src/utility.h

ITERATOR: src/iterator.h src/null_iterator.h src/compound_iterator.h

VISITOR: src/shape_visitor.h src/shape_visitor.cpp

SRC= $(SHAPE) $(ITERATOR)

OBJ= obj/shape_visitor.o

ut_main: test/ut_main.cpp $(TEST) $(SRC) $(OBJ)
	g++ -std=c++11 -Wfatal-errors test/ut_main.cpp $(OBJ) -o bin/ut_all -lgtest -lpthread

obj/shape_visitor.o: src/shape_visitor.cpp src/shape_visitor.h
	g++ -std=c++11 -Wfatal-errors -Wall -c src/shape_visitor.cpp -o obj/shape_visitor.o

directories:
	mkdir -p bin obj

clean:
	rm -rf bin obj
	
test: all
	bin/ut_all
