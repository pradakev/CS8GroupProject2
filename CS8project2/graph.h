#ifndef GRAPH_H
#define GRAPH_H
#include <cassert>
#include <vector>
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

    friend class MainWindow;
    graph();
    ~graph();

    //GETTERS
    stadium getStadiumInfo(string stadiumName);
    int getedge(string stadiumSrc, string stadiumDes);
    List<stadiumNode> getedges(string stadiumSrc);
    List<stadium> getStadiumList() const;

    //SETTERS
    void addStadium(stadium s);
    void addEdge(string src, string des, int distance);

    //FUNCTIONS

    List<stadium> getAmericanLeagueStadiums();
    List<stadium> getNationalLeagueStadiums();
    List<stadium> getStadiumWithGrassField();
    string Dijkstras (stadium);
    string MST (stadium start);




    void updateStadiumList(List<stadium>);


    int getSize();



private:
    void initArr(int arr[], int val);
    void initArr(bool arr[], bool val);
    int smallestIndex(int C[],
                     bool S[]);
    string DisplayMST(int P[],
                    int C[]);

    int indexConversion(string val);
    string stadiumName(int num);
    string displayLinks(int previous[],
                            int stadium);
    string DisplayPath(int P[],
                        int C[]);



    List<stadium> sort(string LeagueType = "all",
                       bool grassSurface = false,
                       bool byTeamName = false,
                       bool byDate = false);


    int getLength(List<stadiumNode>);
    // variable
    List<stadium> stadiums;
    List<List<stadiumNode> > adjList;
    int _size;
};

#endif // GRAPH_H
