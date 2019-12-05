/***************************************
 * AUTHOR                : Justin Kuhn, Anna Ma, Kevin Prada
 * Project 2             : I Love Baseball
 * CLASS                 : CS8
 * SECTION               : MW 9:45-11:10AM TTH 9:45-11:50AM
 * Due Date              : 12/5/19
 * *************************************/

#include "graph.h"
#include <vector>

graph::graph(){}

graph::~graph(){}

/***************************************
 * stadium graph::getStadiumInfo(string stadiumName){
 * --------------------------------------------------------------------
 *  This function returns a stadium object given a sstadium name.
 * --------------------------------------------------------------------
 *  INPUT:
 *      stadiumName - name fo stadiums
 * OUTPUT:
 *     returns the correct stadium object
 *
 * *************************************/
stadium graph::getStadiumInfo(string stadiumName){

    node<stadium>* w = this->stadiums.Begin();
    while (w != nullptr){
        if (w->_item.getStadiumName() == stadiumName){
            return w->_item;
        }else{
            w = w->next;
        }
    }
    return stadium();
}

/***************************************
 * stadiumNode graph::getedge(string stadiumSrc, string stadiumDes){
 * --------------------------------------------------------------------
 *  This function returns the edge between a source and destination stadium.
 * --------------------------------------------------------------------
 *  INPUT:
 *      stadiumSrc - source stadium
 *      stadiumDes - the destination stadium
 * OUTPUT:
 *     returns a node containing the edge length as distance to src
 *
 * *************************************/
stadiumNode graph::getedge(string stadiumSrc, string stadiumDes){

    node<List<stadiumNode>>* w = this->adjList.Begin();
    node<stadiumNode>* w2 = nullptr;
    while (w != nullptr){
        if (w->_item.Begin()->_item._src == stadiumSrc){
            w2 = w->_item.Begin();
            while (w2 != nullptr){
                if (w2->_item._des == stadiumDes){
                    return w2->_item;
                }
                w2 = w2->next;
            }
        }
        w = w->next;
    }
    return stadiumNode();
}
/***************************************
 * List<stadiumNode> graph::getedges(string stadiumSrc){
 * --------------------------------------------------------------------
 *  This function returns all of the edges connected to a source in the form
 *      of a list of stadiumNodes
 * --------------------------------------------------------------------
 *  INPUT:
 *      stadiumSrc - source stadium
 *      stadiumDes - the destination stadium
 * OUTPUT:
 *     returns a node containing the edge length as distance to src
 *
 * *************************************/
List<stadiumNode> graph::getedges(string stadiumSrc){
    List<stadiumNode> returnMe;
    node<List<stadiumNode>>* w = this->adjList.Begin();
    while (w){
        if (w->_item.Begin()->_item._src == stadiumSrc){
            returnMe = w->_item;
            break;
        }
        w = w->next;
    }
    return returnMe;
}

/***************************************
 * void graph::addStadium(stadium s){
 * --------------------------------------------------------------------
 *  This function adss a stadium to the stadiums list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      s - stadium to add
 * OUTPUT:
 *     None
 * *************************************/
void graph::addStadium(stadium s){
    // inserts into stadium list
    this->stadiums.InsertAfter(s,this->stadiums.End());
    _size++;

    // insert into adjlist
    List<stadiumNode> newList;
    stadiumNode toAdd = stadiumNode(s.getStadiumName(), s.getStadiumName(),0);
    newList.InsertHead(toAdd);
    this->adjList.InsertAfter(newList, this->adjList.End());
}

/***************************************
 * void graph::addEdge(string src, string des, int distance){
 * --------------------------------------------------------------------
 *  This function ads an edge to the adjacency list. The node contains
 *      the source, destination, and distance.
 * --------------------------------------------------------------------
 *  INPUT:
 *      src - source stadium
 *      des - destination stadium
 *      distance - distance from destination to source stadium
 * OUTPUT:
 *     None
 * *************************************/
void graph::addEdge(string src, string des, int distance){
    node<List<stadiumNode>>* w = this->adjList.Begin();
    stadiumNode edge =stadiumNode(src, des, distance);


    while (w != nullptr){
        if (w->_item.Begin()->_item._src == src){
            w->_item.InsertAfter(edge, w->_item.End());
        }
        w =w->next;
    }

}

/***************************************
 * int graph::getSize(){
 * --------------------------------------------------------------------
 *  This function returns the number of stadiums associated with this graph.
 * --------------------------------------------------------------------
 *  INPUT:
 *      None
 * OUTPUT:
 *      None
 * *************************************/
int graph::getSize(){
    return _size;
}

/***************************************
 * List<stadium> graph::getStadiumWithGrassField(){
 * --------------------------------------------------------------------
 *  This function returns a list of all of the associated stadiums with a grass
 *      field
 * --------------------------------------------------------------------
 *  INPUT:
 *      None
 * OUTPUT:
 *     returns a list of all stadiums with a grass field
 * *************************************/
List<stadium> graph::getStadiumWithGrassField(){
    List<stadium> returnMe;
    node<stadium>* walker = this->stadiums.Begin();
    while (walker){
        if (walker->_item.getFieldSurface() == "Grass"){
            returnMe.InsertAfter(walker->_item, returnMe.End());
        }
        walker = walker->next;
    }
    return returnMe;
}


/***************************************
 * List<stadium> graph::getStadumList(){
 * --------------------------------------------------------------------
 *  This function returns a list of all the stadiums.
 * --------------------------------------------------------------------
 *  INPUT:
 *      None
 * OUTPUT:
 *     returns a list of af all associated stadiums
 * *************************************/

List<stadium> graph::getStadiumListForDijkstras(){

    return List<stadium>(this->stadiums);
}

/***************************************
 * List<stadium> graph::getAmericanLeagueStadiums(){
 * --------------------------------------------------------------------
 *  This function returns a list of all the american League stadiums
 * --------------------------------------------------------------------
 *  INPUT:
 *      None
 * OUTPUT:
 *     returns a list of af all associated american league stadiums
 * *************************************/
List<stadium> graph::getAmericanLeagueStadiums(){
    List<stadium> returnMe;
    node<stadium>* walker = this->stadiums.Begin();
    while (walker){
        if (walker->_item.getType() == "American"){
            returnMe.InsertAfter(walker->_item, returnMe.End());
        }
        walker = walker->next;
    }
    return returnMe;
}
/***************************************
 * List<stadium> graph::getNationalLeagueStadiums(){
 * --------------------------------------------------------------------
 *  This function returns a list of all the national League stadiums
 * --------------------------------------------------------------------
 *  INPUT:
 *      None
 * OUTPUT:
 *     returns a list of af all associated national league stadiums
 * *************************************/
List<stadium> graph::getNationalLeagueStadiums(){
    List<stadium> returnMe;
    node<stadium>* walker = this->stadiums.Begin();
    while (walker){
        if (walker->_item.getType() == "National"){
            returnMe.InsertAfter(walker->_item, returnMe.End());
        }
        walker = walker->next;
    }
    return returnMe;
}
/***************************************
 * int graph::getLength(List<stadiumNode> l)
 * --------------------------------------------------------------------
 *  This function returns the length of the list of stadium nodes passed.
 * --------------------------------------------------------------------
 *  INPUT:
 *      l - find length of this list
 * OUTPUT:
 *     returnMe - element counter for list l
 * *************************************/
int graph::getLength(List<stadiumNode> l){
    int returnMe =0;
    node<stadiumNode>* w = l.Begin();
    while (w){
        returnMe++;
        w=w->next;
    }
    return returnMe;
}

//////////////////////////////////////////////////////////
// new updates::
/////////////////////////////////////////////////////////

/***************************************
 * List<stadiumNode> graph::shortestPath(const List<stadium>& stadiumList,
 *                                  string src){
 * --------------------------------------------------------------------
 *  This function returns the shortest path to visit all nodes in the list
 *      starting at the source.
 * --------------------------------------------------------------------
 *  INPUT:
 *      stadiumList - find path between all of these stadiums
 *      src - start at this stadium
 * OUTPUT:
 *     a list of stadium nodes representing the visited stadiums.
 * *************************************/
List<stadiumNode> graph::shortestPath(const List<stadium>& stadiumList,
                                      string src){
    List<stadiumNode> result_dijkstras;
    List<stadiumNode> returnMe;

    stadiumNode shortest;

    node<stadiumNode>* walker_for_shortestpath;
    List<stadiumNode> path;

    returnMe.InsertHead(stadiumNode(src, src, 0));

    while(!allVisited(returnMe, stadiumList)){
        initForShortestPath(this->stadiums,result_dijkstras,src);
        dijkstras(result_dijkstras, getedges(src));

        shortest = shortestTotalDistance
                (result_dijkstras, stadiumList, returnMe);

        path = shortestPath(src, shortest._des);

        walker_for_shortestpath = path.Begin();

        while (walker_for_shortestpath){
            returnMe.InsertAfter(walker_for_shortestpath->_item,
                                 returnMe.End());
            walker_for_shortestpath = walker_for_shortestpath->next;
        }
        src = shortest._des;

    }
    return returnMe;
}


/***************************************
 * List<stadiumNode> graph::shortestPath(string src, string des,
 *                                  const List<stadium>& s){
 * --------------------------------------------------------------------
 *  This function returns the shortest path to visit all nodes in the list
 *      starting at the source and ending at the destination.
 * --------------------------------------------------------------------
 *  INPUT:
 *      src - start at this stadium
 *      des - end at this stadium
 * OUTPUT:
 *     a list of stadium nodes representing the visited stadiums.
 * *************************************/
List<stadiumNode> graph::shortestPath(string src,
                                      string des,
                                      const List<stadium>& s){
    //initializing the result list
    List<stadiumNode> result_dijkstras;
    node<stadiumNode>* walker_result =nullptr;
    List<stadiumNode> returnMe;

    if (s.isEmpty()){
        List<stadium>list(this->stadiums);
        initForShortestPath(list, result_dijkstras, src);
    }
    else{
        initForShortestPath(s, result_dijkstras, src);
    }

    // loop through the adjlist to visit all vertex
    dijkstras(result_dijkstras, getedges(src));
    walker_result = result_dijkstras.Begin();

    if (des == src){
        returnMe.InsertHead(getedge(src,des));
        return returnMe;
    }
    do {

        if (walker_result->_item._des == des){
            returnMe.InsertHead(getedge(walker_result->_item._src, des));
            des = getDistance(walker_result->_item._src, result_dijkstras)._des;
            walker_result = result_dijkstras.Begin();

        }
        walker_result = walker_result->next;
        if (walker_result == nullptr){
            walker_result = result_dijkstras.Begin();
        }
    }while (des != src);

    return returnMe;
}

/***************************************
 * void graph::initForShortestPath(const List<stadium>& list,
 *                          List<stadiumNode>& result_dijkstras, string src){
 * --------------------------------------------------------------------
 *  This function initalizes the result_dijkstras list with the values
 *      in list properly formatted for use with dijkstras algo.
 * --------------------------------------------------------------------
 *  INPUT:
 *      list - original list of stadiums
 *      result_dijkstras - formatted list for dijkstras
 *      str - special case for start stadium
 * OUTPUT:
 *     NOne
 * *************************************/
void graph::initForShortestPath(const List<stadium>& list,
                                List<stadiumNode>& result_dijkstras,
                                string src){
    result_dijkstras = List<stadiumNode>();
    node<stadium>* stadiumList_w = list.Begin();

    while (stadiumList_w){
        if (stadiumList_w->_item.getStadiumName() == src){
            result_dijkstras.InsertAfter(stadiumNode(src,src, 0, false),
                                         result_dijkstras.End());
        }else{
            result_dijkstras.InsertAfter(stadiumNode("",
                                        stadiumList_w->_item.getStadiumName(),
                                        10000, false), result_dijkstras.End());
        }
        stadiumList_w = stadiumList_w->next;
    }

}

/***************************************
 * void graph::checkSingleVertex(List<stadiumNode>& returnMe, string src){
 * --------------------------------------------------------------------
 *  This function checks if there is a single vertex in the stadiumNode
 *      list
 * --------------------------------------------------------------------
 *  INPUT:
 *      returnMe - original list of stadiums
 *      src - the source stadium to check
 * OUTPUT:
 *     None
 * *************************************/
void graph::checkSingleVertex(List<stadiumNode>& returnMe, string src){

    node<stadiumNode>* walker_returnMe = returnMe.Begin();

    node<stadiumNode>* walker_adjlist_list = nullptr;
    node<List<stadiumNode>>* w = this->adjList.Begin();
    while (w){
        if (w->_item.Begin()->_item._src == src){
            walker_adjlist_list = w->_item.Begin()->next;
            break;
        }
        w = w->next;
    }

    while (walker_adjlist_list){
        while (walker_returnMe){
            if (walker_returnMe->_item._des == walker_adjlist_list->_item._des){
                if (walker_adjlist_list->_item._distancetoSrc +
                        getDistance(walker_adjlist_list->_item._src,
                                    returnMe)._distancetoSrc
                        < walker_returnMe->_item._distancetoSrc){
                        walker_returnMe->_item._distancetoSrc
                                = walker_adjlist_list->_item._distancetoSrc
                                +getDistance(walker_adjlist_list->_item._src,
                                             returnMe)._distancetoSrc;
                        walker_returnMe->_item._src
                                = walker_adjlist_list->_item._src;
                }else{
                    break;
                }
            }
            walker_returnMe = walker_returnMe->next;
        }
        walker_returnMe = returnMe.Begin();
        walker_adjlist_list = walker_adjlist_list->next;
    }

    while (walker_returnMe) {
        if (walker_returnMe->_item._des == src){
            walker_returnMe->_item._visited = true;
            walker_returnMe = returnMe.Begin();
            break;
        }
        walker_returnMe = walker_returnMe->next;
    }

}

/***************************************
 * bool graph::allVisited(const List<stadiumNode>& me){
 * --------------------------------------------------------------------
 *  This function checks if all of the stadiums have been visited.
 * --------------------------------------------------------------------
 *  INPUT:
 *      me - list of nodes that can be checked
 * OUTPUT:
 *     true or false
 * *************************************/
bool graph::allVisited(const List<stadiumNode>& me){
    node<stadiumNode>* w = me.Begin();
    while (w){
        if (w->_item._visited == false){
            return false;
        }
        w = w->next;
    }
    return true;
}

/***************************************
 * bool graph::allVisited(const List<stadiumNode>& toCheck,
 *                          const List<stadium>& stadiumList){
 * --------------------------------------------------------------------
 *  This function checks if all of the stadiums in the stadium list
 *      have been visited against the toCheck list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      toCheck - check against this list
 *      stadiumList - check this list
 * OUTPUT:
 *     true or false
 * *************************************/
bool graph::allVisited(const List<stadiumNode>& toCheck,
                       const List<stadium>& stadiumList){
    node<stadium>* walker_stadiumList = stadiumList.Begin();

    while(walker_stadiumList){
        if (!checkExist(toCheck, walker_stadiumList->_item.getStadiumName()))
            return false;

        walker_stadiumList = walker_stadiumList->next;
    }
    return true;
}

/***************************************
 * bool graph::checkVisited(const List<stadiumNode>& me, string des){
 * --------------------------------------------------------------------
 *  This function checks if the des stadium name has been visited in the
 *      passed list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      me - check stadium from this list
 *      des - stadium name to check
 * OUTPUT:
 *     true or false
 * *************************************/
bool graph::checkVisited(const List<stadiumNode>& me, string des){
    node<stadiumNode>* w = me.Begin();
    while (w){
        if (w->_item._des == des && w->_item._visited == true)
            return true;
        w = w->next;
    }
    return false;
}
/***************************************
 * stadiumNode graph::getDistance(string des, const List<stadiumNode>& l){
 * --------------------------------------------------------------------
 *  This function returns a node with the the a provided destination
 *      from a list of nodes
 * --------------------------------------------------------------------
 *  INPUT:
 *      des - name of destination
 *      l - list to check
 * OUTPUT:
 *     returns a stadium node with matcing destination
 * *************************************/
stadiumNode graph::getDistance(string des, const List<stadiumNode>& l){
    node<stadiumNode>* temp = l.Begin();

    while (temp){
        if (temp->_item._des == des){
            return stadiumNode(temp->_item);
        }
        temp = temp->next;
    }
    return stadiumNode("","",10000);
}

/***************************************
 * void graph::dijkstras(List<stadiumNode>& getsReturned,
 *                               List<stadiumNode> edges){
 * --------------------------------------------------------------------
 *  This function performs dijkstras on a list of edges and returns
 *      a list of stadiums nodes by ref.
 * --------------------------------------------------------------------
 *  INPUT:
 *      getsReturned - name of stadium node list
 *      edges - the edges to be used in the algorithhm
 * OUTPUT:
 *      Nkne
 * *************************************/
void graph::dijkstras(List<stadiumNode>& getsReturned, List<stadiumNode> edges){

    if (checkVisited(getsReturned, edges.Begin()->_item._src)){
        return;
    }

    node<stadiumNode> * w = edges.Begin();
    checkSingleVertex(getsReturned, w->_item._src);

    while (w){
        dijkstras(getsReturned, getedges(w->_item._des));
        w = w->next;
    }
}

/***************************************
 * stadiumNode graph::shortestTotalDistance
 *                              (const List<stadiumNode>& result_dijkstras){
 * --------------------------------------------------------------------
 *  This function finds the shortest total distance between all of the
 *      nodes in dijkstras.
 * --------------------------------------------------------------------
 *  INPUT:
 *      getsReturned - name of stadium node list
 *      edges - the edges to be used in the algorithhm
 * OUTPUT:
 *      Nkne
 * *************************************/
stadiumNode graph::shortestTotalDistance
                                    (const List<stadiumNode>& result_dijkstras){
    node<stadiumNode>* walker_result = result_dijkstras.Begin();
    int shortest = 10000;
    stadiumNode returnMe;
    while (walker_result){
        if (walker_result->_item._distancetoSrc < shortest &&
                walker_result->_item._src != walker_result->_item._des){
            shortest = walker_result->_item._distancetoSrc;
            returnMe = walker_result->_item;
        }
        walker_result = walker_result->next;
    }
    return returnMe;
}

/***************************************
 * stadiumNode graph::shortestTotalDistance(const List<stadiumNode>& result_dijkstras,
                                         const List<stadium>& toVisit,
                                         const List<stadiumNode>& visited){
 * --------------------------------------------------------------------
 *  This function finds the shortest total distance between all of the
 *      nodes in the toVisit list and only visits them once.
 * --------------------------------------------------------------------
 *  INPUT:
 *      result_dijkstras - the result of previous dijkstras call
 *      toVisit - the stadium that still need to be visited
 *      visited - the stadiums visited
 * OUTPUT:
 *      returns a node represeting shortest total distance
 * *************************************/
stadiumNode graph::shortestTotalDistance(const List<stadiumNode>& result_dijkstras,
                                         const List<stadium>& toVisit,
                                         const List<stadiumNode>& visited){
    node<stadiumNode>* walker_result = result_dijkstras.Begin();
    int shortest = 10000;
    stadiumNode returnMe;


    // list for check exist: toVisit - visited
    List<stadiumNode> toVisitFinal;

    node<stadium>* walker_for_toVisit = toVisit.Begin();
    while (walker_for_toVisit){
        if (!checkExist(visited, walker_for_toVisit->_item.getStadiumName())){
            toVisitFinal.InsertAfter(stadiumNode("",
                                walker_for_toVisit->_item.getStadiumName(), 0),
                                            toVisitFinal.End());

        }
        walker_for_toVisit = walker_for_toVisit->next;
    }

    while (walker_result){
        if (checkExist(toVisitFinal, walker_result->_item._des) &&
                walker_result->_item._distancetoSrc < shortest &&
                    walker_result->_item._src != walker_result->_item._des){
                shortest = walker_result->_item._distancetoSrc;
                returnMe = walker_result->_item;

        }
        walker_result = walker_result->next;

    }

    return returnMe;
}

/***************************************
 * bool graph::checkExist(const List<stadiumNode>& list, string toCheck){
 * --------------------------------------------------------------------
 *  This function checks if the stadium name exists in the passed list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      list - the list of stadium nodes
 *      toCheck - the name of the stadium to check
 * OUTPUT:
 *      true or false
 * *************************************/
bool graph::checkExist(const List<stadiumNode>& list, string toCheck){
    node<stadiumNode>* w = list.Begin();
    while (w){
        if (w->_item._des == toCheck){
            return true;
        }
        w = w->next;
    }
    return false;
}

/***************************************
 * void graph::removeStadium(List<stadiumNode>& list, string toRemove){
 * --------------------------------------------------------------------
 *  This function removes the stadium with the passed name from the passed list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      list - the list of stadium nodes
 *      toRemove - the name of the stadium to remove
 * OUTPUT:
 *      None
 * *************************************/

void graph::removeStadium(List<stadiumNode>& list, string toRemove){
    node<stadiumNode>* w = list.Begin();
    while (w){
        if (w->_item._des == toRemove){
            list.Delete(w);
            break;
        }
        w = w->next;
    }
}


/***************************************
 * void graph::removeStadium(List<stadium>& list, string toRemove){
 * --------------------------------------------------------------------
 *  This function removes the stadium with the passed name from the passed list
 *      of stadiums.
 * --------------------------------------------------------------------
 *  INPUT:
 *      list - the list of stadiums
 *      toRemove - the name of the stadium to remove
 * OUTPUT:
 *      None
 * *************************************/
void graph::removeStadium(List<stadium>& list, string toRemove){
    node<stadium>* w =list.Begin();
    while (w){
        if (w->_item.getStadiumName() == toRemove){
            list.Delete(w);
            break;
        }
        w = w->next;
    }
}
