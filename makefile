.PHONY: clean

SRC = src/square.h src/circle.h
TEST = test/ut_circle.h test/ut_shape.h

all: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

clean:
	rm -f bin/* 
