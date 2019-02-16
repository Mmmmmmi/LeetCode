.PHONY:test
test:isPowerOfTwo.cpp
	g++ -g -Wall -std=c++11  $^ -o $@
