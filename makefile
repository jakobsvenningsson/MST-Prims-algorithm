CFLAGS = -Wall -g -std=c++11

all:
	g++ $(CFLAGS) heap.cpp -o heap.out
