.PHONY: clean

bin/test: test/test.cpp test/test_square.h # what
	g++ -std=c++11 test/test.cpp -o bin/test -lgtest -lpthread

clean:
	rm bin/*
