TEST = test/ut_circle.h test/ut_rectangle.h test/ut_triangle.h test/ut_two_dimensional_vector.h
SRC = src/circle.h src/rectangle.h src/shape.h src/triangle.h src/two_dimensional_vector.h 
bin/ut_all: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

.PHONY: clean
clean:
	rm -f bin/ut_all