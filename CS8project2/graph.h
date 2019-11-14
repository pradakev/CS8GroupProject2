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
    // shortest path between two cities
    List<stadiumNode> shortestPath_TwoCities(string src, string des);

    // takes in a list of stadiums so it will work with customized stadium list
    List<stadiumNode> shortestPath(List<stadium>);

    // making these functions public so that it can be called in the UI,
    //  for purpose of displaying the table
    List<stadium> getAmericanLeagueStadiums();
    List<stadium> getNationalLeagueStadiums();
    List<stadium> getStadiumWithGrassField();

    List<stadium> sort(string LeagueType = "all",
                       bool grassSurface = false,
                       bool byTeamName = false,
                       bool byDate = false);

private:
    // variable
    List<stadium> stadiums;
    List<List<stadiumNode> > adjList;
};

#endif // GRAPH_H
