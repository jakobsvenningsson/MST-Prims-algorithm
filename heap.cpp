#include <iostream>
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
};

bool Heap::empty(){
  if(nodes.size()==0)
    return true;
  return false;
}

void swapNodes(std::vector<Node> &nodes,int i, int j){
  int tmp = nodes[i].priority;
  nodes[i].priority = nodes[j].priority;
  nodes[j].priority = tmp;
}

Node Heap::extractMin(){
  //Save minimum
  Node minimumNode = nodes[0];
  //Replace root node(minimum node) with the last node in the heap
  swapNodes(nodes,0,nodes.size()-1);
  //remove root node
  nodes.pop_back();
  //If heap is empty -> return root node.
  if(empty()){
    return minimumNode;
  }
  // Make heap valid again
  int index = 0;
  // Check if the node at current index has children
  bool leftChildExist = (index*2+1)<nodes.size() ? true : false;
  bool rightChildExist = (index*2+2)<nodes.size() ? true : false;
  //If the node at current index has children with lower values then swap node at index with one of its children.
  while((leftChildExist && nodes[index].priority>nodes[index*2+1].priority)\
   || (rightChildExist && nodes[index].priority>nodes[index*2+2].priority)){
    bool swapLeftChild;
    // If node at current index has two children, swap with the node with lowest value.
    if(leftChildExist && rightChildExist){
       swapLeftChild = nodes[index*2+1].priority > nodes[index*2+2].priority ? false : true;
    }else if(leftChildExist){
      swapLeftChild = true ;
    }else{
      swapLeftChild = false;
    }
    if(swapLeftChild){
      swapNodes(nodes,index,index*2+1);
      index = index*2+2;
    }else{
      swapNodes(nodes,index,index*2+2);
      index = index*2+1;
    }
    //Check if the new node at index has children
    leftChildExist  = (index*2+1)<nodes.size() ? true : false;
    rightChildExist = (index*2+2)<nodes.size() ? true : false;
  }
  return minimumNode;
}

Node Heap::peak(){
  return nodes.at(0);
}

void Heap::insert(Node node){
  if(nodes.size()==0){
    nodes.push_back(node);
  }else{
    nodes.push_back(node);
    int index = nodes.size()-1;
    while(index > 0 && nodes[index].priority<nodes[index/2].priority){
      int tmp = nodes[index].priority;
      nodes[index].priority = nodes[index/2].priority;
      nodes[index/2].priority = tmp;
      index = index/2;
    }
  }
}

int main(){
  Heap heap;
  heap.insert(Node(2,8));
  heap.insert(Node(1,15));
  heap.insert(Node(5,3));
  heap.insert(Node(4,12));
  while(!heap.empty()){
    std::cout << heap.extractMin().priority << std::endl;
  }
  std::cout  << std::endl;
}
