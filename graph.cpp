#include <iostream>
#include "graph.h"


std::map<int,std::list<std::pair<int,int>>> Graph::getVertices(){
    return vertices;
}

void Graph::insertNode(int node){
  auto exist = vertices.find(node);
  if(exist==vertices.end()){
    std::list<std::pair<int,int>> list;
    vertices.insert(std::make_pair(node,list));
  }else{
    std::cout << "Node with same name already exist!" << std::endl;
  }
}

void Graph::insertEdge(int from,int to,int cost){
  auto exist = vertices.find(from);
  if(exist!=vertices.end()){
    exist->second.push_back(std::make_pair(to,cost));
  }else{
    std::cout << "Node "<< from << " does not exist!" << std::endl;
  }
}

std::list<std::pair<int,int>> Graph::getNeightboursOfNode(int node){
  auto exist = vertices.find(node);
  if(exist!=vertices.end()){
    return exist->second;
  }else{
    std::cout << "Node "<< node << " does not exist!" << std::endl;
    return {};
  }
}
