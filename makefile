.PHONY:test
test:maxSubArray.cc
	g++ -g -Wall -std=c++11  $^ -o $@
