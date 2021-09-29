.PHONY: clean

SRC = src/square.h src/circle.h src/IOHandler.h
TEST = test/test_IOHandler.h test/test_square.h test/test_circle.h test/test_shape.h

all: test/test.cpp src/IOHandler.cpp $(TEST) $(SRC)
	g++ -std=c++11 test/test.cpp src/IOHandler.cpp -o bin/ut_all -lgtest -lpthread

clean:
	rm -f bin/* 
