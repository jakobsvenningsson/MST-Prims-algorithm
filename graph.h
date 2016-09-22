#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <list>
#include <utility>
class Graph{
  public:
    void insertNode(char);
    void insertEdge(char,char,int);
    std::list<std::pair<char,int>> getNeightboursOfNode(char);
  private:
    std::map<char,std::list<std::pair<char,int>>> vertices;
};

#endif
