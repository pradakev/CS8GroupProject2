/***************************************
 * AUTHOR                : Justin Kuhn, Anna Ma, Kevin Prada
 * Project 2             : I Love Baseball
 * CLASS                 : CS8
 * SECTION               : MW 9:45-11:10AM TTH 9:45-11:50AM
 * Due Date              : 12/5/19
 * *************************************/

#ifndef GRAPH_H
#define GRAPH_H
#include <cassert>
#include <vector>
#include "list.h"
#include "stadium.h"


/*******************************************************************
 *  StadiumNode struct
 *     This structure represents the connections between stadiums
 *      and their respective edges
 * *****************************************************************/

struct stadiumNode{

    // Default Constructor
    stadiumNode(){}
    // Construcor that initialzed all attributes with default visited = f
    stadiumNode(string src, string des, int dist, bool visited = false){
        _src = src;
        _des = des;
        _distancetoSrc = dist;
        _visited = visited;
    }
    string _src;        // ATT - the source stadium
    string _des;        // ATT - the destination stadium
    int _distancetoSrc; // ATT - the distance to the source
    bool _visited;      // ATT - if this stadium has been visited

    /*******************************************************************
     *  friend ostream& operator << (ostream& out, const stadiumNode& l){
     *     This overloaded extraction operator properly displays the
     *      relevent values for a stadium node
     * *****************************************************************/

    friend ostream& operator << (ostream& out,              // OUT - output str
                                 const stadiumNode& l){     // IN -  node to out
        out << l._src << ", " << l._des << ", " << l._distancetoSrc;
        return out;
    }


};


class graph
{
public:

    friend class MainWindow;
    // Default constructor (no change)
    graph();
    // Default destructor (no change)
    ~graph();

    //GETTERS
    /*******************************************************************
     *   stadium getStadiumInfo(string stadiumName);
     *     This function returns a stadium object from the stadium list with
     *      the passed name.
     * *****************************************************************/
    stadium getStadiumInfo(string stadiumName); // IN -  stadium name
    /*******************************************************************
     *  stadiumNode getedge(string stadiumSrc, string stadiumDes);
     *     This function returns the edge connecteing the two passed names.
     *      The edge is represented with a stadiumNode.
     * *****************************************************************/
    stadiumNode getedge(string stadiumSrc, // IN -  stadium source name
                        string stadiumDes);// IN -  stadium destination name
    /*******************************************************************
     *  List<stadiumNode> getedges(string stadiumSrc);
     *     This function returns all of the edges originating
     *      from the source stadium.
     * *****************************************************************/
    List<stadiumNode> getedges(string stadiumSrc); // IN -  stadium source name

    //SETTERS
    /*******************************************************************
     *   void addStadium(stadium s);
     *     This function adds the stadium to the stadium list
     * *****************************************************************/
    void addStadium(stadium s); // IN -  stadium to add to list
    /*******************************************************************
     *  void addEdge(string src, string des, int distance);
     *     This function adds an edge to the adjacency list
     * *****************************************************************/
    void addEdge(string src,        // IN -  stadium source to add
                 string des,        // IN -  stadium desintaton to add
                 int distance);     // IN -  distance between

    //FUNCTIONS
    /*******************************************************************
     *  List<stadium> getAmericanLeagueStadiums();
     *     This function returns a list of stadiums containing all
     *      American league stadiums.
     * *****************************************************************/
    List<stadium> getAmericanLeagueStadiums();
    /*******************************************************************
     *   List<stadium> getNationalLeagueStadiums();
     *     This function returns a list of stadiums containing all
     *      National league stadiums.
     * *****************************************************************/
    List<stadium> getNationalLeagueStadiums();
    /*******************************************************************
     *  List<stadium> getStadiumWithGrassField();
     *     This function returns a list of stadiums containing a
     *      a grass field.
     * *****************************************************************/
    List<stadium> getStadiumWithGrassField();
    /*******************************************************************
     *  List<stadium> getStadiumWithGrassField();
     *     This function returns a list of all of the stadiums.
     * *****************************************************************/
    List<stadium> getStadumList();


    /*******************************************************************
     *  int getSize();
     *     This function returns the size attribute of the graph
     * *****************************************************************/
    int getSize();


    ////////////////////// new updates::


    /*******************************************************************
     *   List<stadiumNode> shortestPath(string src, string des,
     *                          const List<stadium>& = List<stadium>());
     *     This function returns a list of stadium nodes with the
     *      shortest path from the src to the destination.
     * *****************************************************************/
    List<stadiumNode> shortestPath(string src,  // IN -  stadium source name
                                   string des,  // IN -  stadium destin name
        const List<stadium>& = List<stadium>());// IN -  list to visit
    /*******************************************************************
     *  List<stadiumNode> shortestPath(const List<stadium>&, string src);
     *
     *     This function returns a list of stadium nodes with the
     *      that visits alll the stadiums in the list with the shortest
     *      total distance.
     * *****************************************************************/
    List<stadiumNode> shortestPath(const List<stadium>&,// IN -  list to visit
                                   string src);         // IN -  stadium to strt

    /*******************************************************************
     *  stadiumNode getDistance(string des, const List<stadiumNode>&);
     *
     *     This function returns the total distance to the destination
     *      while given all the nodes in the list are visited
     * *****************************************************************/
    stadiumNode getDistance(string des,     // IN - destination
                const List<stadiumNode>&);  // IN - list of nodes visited
    /*******************************************************************
     *  void checkSingleVertex(List<stadiumNode>& getsReturned, string src);
     *
     *     This function checks if there are any single vertices in the
     *      passed list
     * *****************************************************************/
    void checkSingleVertex(List<stadiumNode>& getsReturned, // IN -  list to chk
                           string src);                     // IN -  source std
    /*******************************************************************
     *  void dijkstras(List<stadiumNode>& getsReturned, List<stadiumNode>edges);
     *
     *     This function performs dijkstras algorithm on the passed
     *      list of edges. It edits the list of stadiums visited passed.
     * *****************************************************************/
    void dijkstras(List<stadiumNode>& getsReturned,  // IN -  stadium connection
                   List<stadiumNode> edges);         // IN - used to cal path
    /*******************************************************************
     *  bool allVisited(const List<stadiumNode>&);
     *
     *     This function checks if all of the stadiums in the list are visited
     * *****************************************************************/
    bool allVisited(const List<stadiumNode>&);  // IN -  list to check
    /*******************************************************************
     *  bool allVisited(const List<stadiumNode>&, const List<stadium>&);
     *
     *     This function checks if all the stadiums in the other list have
     *      been visited.
     * *****************************************************************/
    bool allVisited(const List<stadiumNode>&,   // IN -  list to check against
                    const List<stadium>&);      // IN -  list to check

    /*******************************************************************
     *  bool checkVisited(const List<stadiumNode>& me, string des);
     *
     *     This function if the destination has been visited in the
     *      passed list
     * *****************************************************************/
    bool checkVisited(const List<stadiumNode>& me,// IN -  list to check
                      string des);                // IN -  stadium name to check
    /*******************************************************************
     *  stadiumNode shortestTotalDistance(const List<stadiumNode>&);
     *
     *     This function returns a stadium node representing the
     *      shortest distance to visit all nodes in the list
     * *****************************************************************/
    stadiumNode shortestTotalDistance
            (const List<stadiumNode>&);// IN - list with distances
    /*******************************************************************
     *      stadiumNode shortestTotalDistance(const List<stadiumNode>&
     *                                              result_dijkstras,
     *                                 const List<stadium>& toVisit,
     *                                 const List<stadiumNode>& visited);
     *
     *     This function returns a stadium node representing the
     *      shortest distance to visit all nodes in the toVisit list
     *      using the result of dijkstras and the stadiums already visited
     * *****************************************************************/
    stadiumNode shortestTotalDistance
        (const List<stadiumNode>& result_dijkstras, // IN -  previous alg result
                    const List<stadium>& toVisit,   // IN - stadiums to visit
                const List<stadiumNode>& visited);  // IN - stadiums visited
    /*******************************************************************
     *  void initForShortestPath(const List<stadium>&,
     *                                      List<stadiumNode>&, string src);
     *
     *     This function initalizes the list with the shortest
     *          path starting from the source stadium.
     * *****************************************************************/
    void initForShortestPath(const List<stadium>&, // IN - stadiums to visit
                             List<stadiumNode>&,   // IN - init this
                             string src);          // IN - start here
    /*******************************************************************
     *  bool checkExist(const List<stadiumNode>&, string toCheck);
     *
     *     This function checks if the stadium exists in the list.
     * *****************************************************************/
    bool checkExist(const List<stadiumNode>&, // IN - check this list
                    string toCheck);          // IN - if this exits
    /*******************************************************************
     *  void removeStadium(List<stadiumNode>&, string toRemove);
     *
     *     This function removes the stadium from the list of stadium
     *      nodes.
     * *****************************************************************/
    void removeStadium(List<stadiumNode>&,      // IN - list to remove val
                       string toRemove);        // IN - nm of stadium to rem
    /*******************************************************************
     *  void removeStadium(List<stadium>&, string toRemove);
     *
     *     This function removes the stadium from the list of stadiums.
     * *****************************************************************/
    void removeStadium(List<stadium>&,         // IN - list to remove val
                       string toRemove);       // IN - nm of stadium to rem

    ////////////////////////////////////////

private:

    /*******************************************************************
     *    List<stadium> sort(string LeagueType = "all",
     *                  bool grassSurface = false,
     *                  bool byTeamName = false,
     *                  bool byDate = false);
     *
     *     This function returns a list of stadiums with the specified
     *      criteria.
     * *****************************************************************/
    List<stadium> sort(string LeagueType = "all",   // IN - sort by league
                       bool grassSurface = false,   // IN - sort by surface
                       bool byTeamName = false,     // IN - sort by team name
                       bool byDate = false);        // IN - sort by open date

    /*******************************************************************
     *  int getLength(List<stadiumNode>);
     *
     *     This function returns the length of a list of stadium nodes
     * *****************************************************************/
    int getLength(List<stadiumNode>);

    List<stadium> stadiums;             // ATT - list of stadiums
    List<List<stadiumNode> > adjList;   // ATT - list of edges
    int _size;                          // ATT - total # of stadiums
};

#endif // GRAPH_H
