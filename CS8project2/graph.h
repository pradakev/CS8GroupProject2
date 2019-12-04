#ifndef GRAPH_H
#define GRAPH_H
#include <cassert>
#include <vector>
#include "list.h"
#include "stadium.h"

struct stadiumNode{

    stadiumNode(){}
    stadiumNode(string src, string des, int dist, bool visited = false){
        _src = src;
        _des = des;
        _distancetoSrc = dist;
        _visited = visited;
    }
    string _src;
    string _des;
    int _distancetoSrc;
    bool _visited;


    friend ostream& operator << (ostream& out, const stadiumNode& l){
        out << "(" << l._src << ", " << l._des << ") " << l._distancetoSrc;
        return out;
    }


};

class graph
{
public:

    friend class MainWindow;
    graph();
    ~graph();

    //GETTERS
    stadium getStadiumInfo(string stadiumName);
    stadiumNode getedge(string stadiumSrc, string stadiumDes);
    List<stadiumNode> getedges(string stadiumSrc);

    //SETTERS
    void addStadium(stadium s);
    void addEdge(string src, string des, int distance);

    //FUNCTIONS
    List<stadium> getAmericanLeagueStadiums();
    List<stadium> getNationalLeagueStadiums();
    List<stadium> getStadiumWithGrassField();
    List<stadium> getStadumList();



    string Dijkstras (stadium);
    string MST (stadium start);

    int getSize();


    ////////////////////// new updates::


    List<stadiumNode> shortestPath(string src, string des, const List<stadium>& = List<stadium>());
    List<stadiumNode> shortestPath(const List<stadium>&, string src);

    stadiumNode getDistance(string des, const List<stadiumNode>&);
    void checkSingleVertex(List<stadiumNode>& getsReturned, string src);
    void dijkstras(List<stadiumNode>& getsReturned, List<stadiumNode> edges);
    bool allVisited(const List<stadiumNode>&);
    bool allVisited(const List<stadiumNode>&, const List<stadium>&);
    bool checkVisited(const List<stadiumNode>& me, string des);
    stadiumNode shortestTotalDistance(const List<stadiumNode>&);
    stadiumNode shortestTotalDistance(const List<stadiumNode>& result_dijkstras,
                                      const List<stadium>& toVisit,
                                      const List<stadiumNode>& visited);
    void initForShortestPath(const List<stadium>&, List<stadiumNode>&, string src);
    bool checkExist(const List<stadiumNode>&, string toCheck);
    void removeStadium(List<stadiumNode>&, string toRemove);
    void removeStadium(List<stadium>&, string toRemove);

    ////////////////////////////////////////

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
