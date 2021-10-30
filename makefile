.PHONY: clean dirs

SRC = src/shape.h src/rectangle.h src/circle.h src/triangle.h \
	  src/two_dimensional_vector.h

TEST = test/ut_shape.h test/ut_rectangle.h test/ut_circle.h test/ut_triangle.h \
	   test/ut_two_dimensional_vector.h

all: dirs ut_main

ut_main: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

clean:
	rm -f bin/ut_all

dirs:
	mkdir -p bin