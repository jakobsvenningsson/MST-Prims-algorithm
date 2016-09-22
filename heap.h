#ifndef HEAP_H
#define HEAP_H
#include <vector>

struct Node{
  Node(int p,int v):priority(p),value(v){}
  int priority;
  int value;
};

class Heap{
  private:
    std::vector<Node> nodes;
  public:
    void insert(Node);
    Node peak();
    Node extractMin();
    bool empty();
    void changePriority(int,int);
    void print();
    bool exist(int);
};
#endif
