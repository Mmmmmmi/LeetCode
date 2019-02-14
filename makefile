.PHONY:containsDuplicate
containsDuplicate:containsDuplicate.cpp
	g++ -g -Wall -std=c++11  $^ -o $@
