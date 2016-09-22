#include <iostream>
#include <random>
#include <ctime>
#include "heap.h"

bool Heap::exist(int value){
  for(auto node:nodes){
    if(value==node.value){
      return true;
    }
  }
  return false;
}

bool Heap::empty(){
  if(nodes.size()==0)
    return true;
  return false;
}

void swapNodes(std::vector<Node> &nodes,int i, int j){
  Node tmp = nodes[i];
  nodes[i]= nodes[j];
  nodes[j]= tmp;
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
      index = index*2+1;
    }else{
      swapNodes(nodes,index,index*2+2);
      index = index*2+2;
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
void Heap::changePriority(int value,int priority){
  int index=-1;
  for(int i = 0 ; i < nodes.size() ; ++i){
    if(nodes[i].value==value){
      nodes[i].priority = priority;
      nodes[i].value = value;
      index = i;
    }
  }
  if(index==-1){
    std::cout << "No node with value " << value << " was found in the heap";
    return;
  }
  if(index==0){
    return;
  }
  while(nodes[index].priority<nodes[index/2].priority){
    Node tmp = nodes[index];
    nodes[index] = nodes[index/2];
    nodes[index/2] = tmp;
    index = index/2;
  }
}

void Heap::print(){
  for(auto node:nodes)
    std::cout << "(" << node.priority << "," << node.value << ") ";
  std::cout << std::endl;
}
