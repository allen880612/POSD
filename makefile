.PHONY: clean test

all: directories ut_main

TEST: test/ut_rectangle.h test/ut_circle.h test/ut_triangle.h \
	  test/ut_two_dimensional_vector.h test/compound_shape.h test/iterator.h \
	  test/ut_utility.h

SHAPE: src/shape.h src/rectangle.h src/circle.h src/triangle.h \
	   src/two_dimensional_vector.h src/compound_shape.h src/utility.h

ITERATOR: src/iterator.h src/null_iterator.h src/compound_iterator.h

SRC: $(SHAPE) $(ITERATOR)

ut_main: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++11 -Wfatal-errors test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean:
	rm -rf bin
	
test: all
	bin/ut_all
