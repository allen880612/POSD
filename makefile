.PHONY: clean dirs

SRC = src/rectangle.h src/circle.h
TEST = test/ut_rectangle.h test/ut_circle.h test/ut_shape.h

all: dirs ut_main

ut_main: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

clean:
	rm -f bin/* 

dirs:
	mkdir -p bin