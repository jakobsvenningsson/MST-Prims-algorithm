#include <iostream>
#include <vector>


class Heap{
  private:
  public:
    std::vector<int> nodes;
    void insert(int);
    int peak();
    int extractMin();
    void print();
    bool empty();

};

bool Heap::empty(){
  if(nodes.size()==0)
    return true;
  return false;
}

void Heap::print(){
  for(auto node : nodes)
    std::cout << node << " ";
  std::cout << std::endl;
}

int Heap::extractMin(){
  int min = nodes[0];
  nodes[0] = nodes[nodes.size()-1];
  nodes[nodes.size()-1]=min;
  nodes.pop_back();
  if(empty()){
    return min;
  }
  int index = 0;

  bool leftChildExist = (index*2+1)<nodes.size() ? true : false;
  bool rightChildExist = (index*2+2)<nodes.size() ? true : false;
  while((leftChildExist && nodes[index]>nodes[index*2+1]) || (rightChildExist && nodes[index]>nodes[index*2+2])){
    //std::cout << "While begin" << std::endl;
    int rightChild,leftChild,swap;
    if(leftChildExist && rightChildExist){
       leftChild = nodes[index*2+1];
       rightChild =nodes[index*2+2];
       swap = leftChild>rightChild ? 1 : 0;
    }else if(leftChildExist){
      leftChild = nodes[index*2+1];
      swap = 0;
    }else{
      rightChild =nodes[index*2+2];
      swap = 1;
    }
    if(swap){
      int tmp = nodes[index];
      nodes[index] = rightChild;
      nodes[index*2+2] = tmp;
      index = index*2+2;
    }else{
      int tmp = nodes[index];
      nodes[index] = leftChild;
      nodes[index*2+1] = tmp;
      index = index*2+1;
    }
    leftChildExist  = (index*2+1)<nodes.size() ? true : false;
    rightChildExist = (index*2+2)<nodes.size() ? true : false;
  }

  return min;
}

int Heap::peak(){
  return nodes.at(0);
}

void Heap::insert(int elem){
  if(nodes.size()==0){
    nodes.push_back(elem);
  }else{
    nodes.push_back(elem);
    int index = nodes.size()-1;
    while(index > 0 && nodes[index]<nodes[index/2]){
      int tmp = nodes[index];
      nodes[index] = nodes[index/2];
      nodes[index/2] = tmp;
      index = index/2;
    }
  }
}

int main(){
  Heap heap;
  heap.insert(3);
  heap.insert(3);
  heap.insert(3);
  heap.insert(1);
  heap.insert(3);
  heap.insert(312);
  heap.insert(3);
  heap.insert(3);
  heap.insert(23);
  heap.insert(3);
  heap.insert(3);
  heap.insert(23);
  heap.insert(3);



  while(!heap.empty()){
    //heap.print();
    //std::cout << "------" << std::endl;
    std::cout << heap.extractMin() << std::endl;
  }
  std::cout  << std::endl;



  /*heap.print();
  heap.extractMin();
  heap.print();
  int index = 2;
  std::cout << "Parent: " << heap.nodes.at(index) << std::endl;
  std::cout << "Left child: " << heap.nodes.at(index*2+1) << std::endl;
  std::cout << "right child: " << heap.nodes.at(index*2+2) << std::endl;*/


}
