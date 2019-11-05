#ifndef GRAPH_H
#define GRAPH_H
#include "list.h"
#include "stadium.h"

struct stadiumNode{

    stadium _s;
    int _distancetoSrc;

};

class graph
{
public:
    graph();

    //GETTERS


    //SETTERS

private:
    List<List<stadiumNode>> stadiumList;
};

#endif // GRAPH_H
