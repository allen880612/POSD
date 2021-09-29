.PHONY: clean

SRC = src/square.h src/IOHandler.h

TEST = test/test_IOHandler.h test/test_square.h

bin/test: test/test.cpp src/IOHandler.cpp ${TEST} ${SRC}  # what
	g++ -std=c++11 test/test.cpp src/IOHandler.cpp -o bin/test -lgtest -lpthread

clean:
	rm -f bin/*