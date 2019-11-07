#ifndef GRAPH_H
#define GRAPH_H
#include "linked_list_functions.h"
#include "stadium.h"

struct stadiumNode{

    stadiumNode(){}
    stadiumNode(stadium s, int dist){
        _s = s;
        _distancetoSrc = dist;
    }
    stadium _s;
    int _distancetoSrc;

};

class graph
{
public:
    graph();
    ~graph();

    //GETTERS
    stadium getStadium(string stadiumName);
    int getedge(string stadiumSrc, string stadiumDes);

    //SETTERS
    void addStadium(stadium s);
    void addEdge(stadium src, stadium des, int distance);

    //FUNCTIONS

private:
    node<node<stadiumNode>*>* stadiumList;
};

#endif // GRAPH_H
