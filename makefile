CFLAGS = -Wall -g -std=c++11

all:
	g++ $(CFLAGS) heap.cpp prim.cpp -o heap.out

graph.out:graph.cpp
	g++ $(CFLAGS) graph.cpp -o graph.out


clean:
	rm -rf *.dSYM *.out *.o
