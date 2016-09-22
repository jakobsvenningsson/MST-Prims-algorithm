#include <iostream>
#include "graph.h"
void Graph::insertNode(char node){
  auto exist = vertices.find(node);
  if(exist==vertices.end()){
    std::list<std::pair<char,int>> list;
    vertices.insert(std::make_pair(node,list));
  }else{
    std::cout << "Node with same name already exist!" << std::endl;
  }
}

void Graph::insertEdge(char from,char to,int cost){
  auto exist = vertices.find(from);
  if(exist!=vertices.end()){
    exist->second.push_back(std::make_pair(to,cost));
  }else{
    std::cout << "Node "<< from << " does not exist!" << std::endl;
  }
}

std::list<std::pair<char,int>> Graph::getNeightboursOfNode(char node){
  auto exist = vertices.find(node);
  if(exist!=vertices.end()){
    return exist->second;
  }else{
    std::cout << "Node "<< node << " does not exist!" << std::endl;
    return {};
  }
}


/*int main(){
  Graph g;
  g.insertNode('x');
  g.insertNode('z');
  g.insertEdge('x','y',2);
  std::list<std::pair<char,int>> c = g.getNeightboursOfNode('x');
  for(auto n:c)
    std::cout << n.first << " " << n.second << std::endl;

  return 0;
}*/
