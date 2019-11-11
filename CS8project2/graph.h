#ifndef GRAPH_H
#define GRAPH_H
#include "list.h"
#include "stadium.h"

struct stadiumNode{

    stadiumNode(){}
    stadiumNode(string src, string des, int dist){
        _src = src;
        _des = des;
        _distancetoSrc = dist;
        _visited = false;
    }
    string _src;
    string _des;
    int _distancetoSrc;
    bool _visited;

};

class graph
{
public:
    graph();
    ~graph();

    //GETTERS
    stadium getStadiumInfo(string stadiumName);
    int getedge(string stadiumSrc, string stadiumDes);
    List<stadiumNode> getedges(string stadiumSrc);

    //SETTERS
    void addStadium(stadium s);
    void addEdge(string src, string des, int distance);

    //FUNCTIONS

private:
    bool hasStadium(string name);

    List<stadium> stadiums;
    List<List<stadiumNode> > adjList;
};

#endif // GRAPH_H
