CFLAGS = -Wall -g -std=c++11

all:graph.o heap.o prim.o
	g++ $(CFLAGS) prim.o  graph.o heap.o -o prim.out

prim.o:prim.cpp
	g++ $(CFLAGS) prim.cpp -c

graph.o:graph.cpp
	g++ $(CFLAGS) graph.cpp -c

heap.o:heap.cpp
	g++ $(CFLAGS) heap.cpp -c

clean:
	rm -rf *.dSYM *.out *.o
