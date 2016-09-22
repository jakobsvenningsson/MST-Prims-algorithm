#include <iostream>
#include "heap.h"
#include "graph.h"
#include <limits>
#include <map>
#include <list>
#include <utility>


// Finds a MST of the given graph passed as argument, uses Prim's algorithm to achieve this.
void prim(Heap heap,Graph g, int start){
  std::map<int,int> key;
  int pii[g.getVertices().size()];
  for(auto vertex:g.getVertices()){
    heap.insert(Node(std::numeric_limits<int>::max(),vertex.first));
    key.insert(std::make_pair(vertex.first,std::numeric_limits<int>::max()));
  }
    pii[0]=-1;
    key[start] = 0;
    heap.changePriority(start,0);
    while(!heap.empty()){
    Node u = heap.extractMin();
    std::list<std::pair<int,int>> neighbours = g.getNeightboursOfNode(u.value);
    for(auto neighbour:neighbours){
      if(heap.exist(neighbour.first) && neighbour.second<key[neighbour.first]){
        pii[neighbour.first] = u.value;
        key[neighbour.first] = neighbour.second;
        heap.changePriority(neighbour.first,neighbour.second);
      }
    }
  }
  int i = 0;
  for(auto x:pii){
    std::cout << "Parent of " <<  i << " is " << x << std::endl;
    ++i;
  }
}
int main(){
  Heap heap;
  Graph g;
  g.insertNode(0);
  g.insertNode(1);
  g.insertNode(2);
  g.insertNode(3);
  g.insertNode(4);
  g.insertEdge(0,3,3);
  g.insertEdge(3,1,23);
  g.insertEdge(1,2,10);
  g.insertEdge(2,0,30);
  g.insertEdge(2,3,3);
  g.insertEdge(3,4,9);
  g.insertEdge(4,0,20);
  g.insertEdge(4,3,1);
  g.insertEdge(1,0,1);




  prim(heap,g,0);

}
