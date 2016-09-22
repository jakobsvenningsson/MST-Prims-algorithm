#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <list>
#include <utility>
class Graph{
  public:
    std::map<int,std::list<std::pair<int,int>>> getVertices();
    void insertNode(int);
    void insertEdge(int,int,int);
    std::list<std::pair<int,int>> getNeightboursOfNode(int);
  private:
    std::map<int,std::list<std::pair<int,int>>> vertices;
};

#endif
