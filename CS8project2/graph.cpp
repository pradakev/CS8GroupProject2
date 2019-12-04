#include "graph.h"
#include <vector>

graph::graph(){}

graph::~graph(){}

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

int graph::getSize(){
    return _size;
}

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

List<stadium> graph::getStadumList(){
    return List<stadium>(this->stadiums);
}

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

string graph::Dijkstras (stadium start)
{

    int C[this->getSize()];
    int P[this->getSize()];
    bool S[this->getSize()];

    initArr(C,INT_MAX);
    initArr(P,-1);
    initArr(S, 0);


    C[indexConversion(start.getStadiumName())] = 0;


    for (int count = 0; count < this->getSize() - 1; count++) {

        int k = smallestIndex(C, S);

        S[k] = true;

        for (int i = 0; i <  getLength(adjList[i]); i++)

        {
            int true_index = indexConversion(adjList[k][i]._des);
            if (!S[true_index]
                    && adjList[k][i]._distancetoSrc != 0
                    && C[k] != INT_MAX
                    && C[k] + adjList[k][i]._distancetoSrc
                    < C[true_index])
            {
                C[true_index]
                        = C[k] + adjList[k][i]._distancetoSrc;
                P[true_index] = k;
            }
        }

    }
    return DisplayPath(P,C);
}

string graph::MST (stadium start)
{
    int C[this->getSize()];
    int P[this->getSize()];
    bool S[this->getSize()];

    initArr(C,INT_MAX);
    initArr(P,-1);
    initArr(S, 0);



    C[indexConversion(start.getStadiumName())] = 0;

    for (int count = 0; count < this->getSize() - 1; count++) {

        int k = smallestIndex(C, S);

        S[k] = true;

        for (int i = 0; i <  getLength(adjList[i]); i++)

        {
            int true_index = indexConversion(adjList[k][i]._des);
            if (!S[true_index]
                    && adjList[k][i]._distancetoSrc != 0
                    && C[k] != INT_MAX
                    && adjList[k][i]._distancetoSrc
                    < C[true_index])
            {
                C[true_index]
                        = adjList[k][i]._distancetoSrc;
                P[true_index] = k;
            }
        }

    }
    return DisplayMST(P,C);

}


void graph::initArr(int arr[], int val)
{
    for(int i = 0; i < this->getSize(); i++)

    {
        arr[i] = val;
    }
}
void graph::initArr(bool arr[], bool val)
{
    for(int i = 0; i < this->getSize(); i++)

    {
        arr[i] = val;
    }
}

int graph::smallestIndex(int C[],   // IN - array to find smallest
                         bool S[])  // IN - check uniqueness
{

    int smallest = INT_MAX;
    int smallest_index = 0;

    for (int i = 0; i < this->getSize(); i++)

    {
        if (C[i] < smallest && !S[i])
        {
            smallest_index = i;
            smallest = C[i];
        }
    }
    return smallest_index;
}
int graph::indexConversion(string val)
{
    for(int i = 0; i < this->getSize(); i++)

    {
        if(adjList[i].Begin()->_item._src == val)
        {
            return i;
        }
    }

    return -1;
}


string graph::DisplayMST(int P[], // IN - link to previous
                         int C[]) // IN - node distances
{
    int total;  // IN - the total distance travelled;
    string final = "";
    total = 0;

    for (int i = 1; i < this->getSize(); i++)

    {

        final +=  to_string(i) + ". " + "( " + stadiumName(i)
                 + " " + stadiumName(P[i]) + " ) ";

        final += " " + to_string(C[i]) + "\n";
        total += C[i];

    }
    final += "\n";
    final += "Total: " + to_string(total) + "\n";
    return final;
}


string graph::DisplayPath(int P[],   // IN - links to previous
                        int C[])   // IN - node distances
{
    string final = "";
    for (int i = 0; i < this->getSize(); i++)

    {
        final += stadiumName(i) + ":" + to_string(C[i]);

        final += displayLinks(P,i) + "\n";
    }
    return final;

}


string graph::displayLinks(int previous[],  // IN - links to previous
                         int stadium)        // IN - starting index
{
    vector<string> temp;

    string final = "";

    while (stadium != -1)
    {
        temp.push_back(stadiumName(stadium));
        if (stadium != 0)
        {
            stadium = previous[stadium];
        }
        else stadium = -1;
    }
    final += "{ ";

    for(vector<string>::iterator it = temp.end()-1;

        it >= temp.begin(); it--)
    {
        final += *it + "  ";
    }

    return (final += "}");

}

string graph::stadiumName(int num)  // IN - number to convert
{
    return adjList[num].Begin()->_item._src;
}

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
List<stadiumNode> graph::shortestPath(string src, string des, const List<stadium>& s){
    //initializing the result list
    List<stadiumNode> result_dijkstras;
    node<stadiumNode>* walker_result = nullptr;
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
    }while (des != src);

    return returnMe;

}

void graph::initForShortestPath(const List<stadium>& list, List<stadiumNode>& result_dijkstras, string src){
    result_dijkstras = List<stadiumNode>();
    node<stadium>* stadiumList_w = list.Begin();

    while (stadiumList_w){
        if (stadiumList_w->_item.getStadiumName() == src){
            result_dijkstras.InsertAfter(stadiumNode(src,src, 0, false), result_dijkstras.End());
        }else{
            result_dijkstras.InsertAfter(stadiumNode("", stadiumList_w->_item.getStadiumName(),
                              10000, false), result_dijkstras.End());
        }
        stadiumList_w = stadiumList_w->next;
    }

}

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
                if (!checkExist(returnMe, walker_adjlist_list->_item._src)){
                    break;
                }
                if (walker_adjlist_list->_item._distancetoSrc +
                        getDistance(walker_adjlist_list->_item._src, returnMe)._distancetoSrc
                        < walker_returnMe->_item._distancetoSrc){
                        walker_returnMe->_item._distancetoSrc = walker_adjlist_list->_item._distancetoSrc
                                +getDistance(walker_adjlist_list->_item._src, returnMe)._distancetoSrc;
                        walker_returnMe->_item._src = walker_adjlist_list->_item._src;
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

bool graph::allVisited(const List<stadiumNode>& toCheck, const List<stadium>& stadiumList){
    node<stadium>* walker_stadiumList = stadiumList.Begin();

    while(walker_stadiumList){
        if (!checkExist(toCheck, walker_stadiumList->_item.getStadiumName()))
            return false;
        walker_stadiumList = walker_stadiumList->next;
    }
    return true;
}

bool graph::checkVisited(const List<stadiumNode>& me, string des){
    node<stadiumNode>* w = me.Begin();
    while (w){
        if (w->_item._des == des && w->_item._visited == true)
            return true;
        w = w->next;
    }
    return false;
}
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

void graph::dijkstras(List<stadiumNode>& getsReturned, List<stadiumNode> edges){

    if (!checkExist(getsReturned, edges.Begin()->_item._src)){
        return;
    }
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

stadiumNode graph::shortestTotalDistance(const List<stadiumNode>& result_dijkstras){
    node<stadiumNode>* walker_result = result_dijkstras.Begin();
    int shortest = 10000;
    stadiumNode returnMe;
    while (walker_result){
        if (walker_result->_item._distancetoSrc < shortest && walker_result->_item._src != walker_result->_item._des){
            shortest = walker_result->_item._distancetoSrc;
            returnMe = walker_result->_item;
        }
        walker_result = walker_result->next;
    }
    return returnMe;
}

stadiumNode graph::shortestTotalDistance(const List<stadiumNode>& result_dijkstras,
                                         const List<stadium>& toVisit,
                                         const List<stadiumNode>& visited){
    node<stadiumNode>* walker_result = result_dijkstras.Begin();
    int shortest = 10000;
    stadiumNode returnMe;


    // list for check exist: toVisit - visited
    List<stadiumNode> list_for_checkExist;

    node<stadium>* walker_for_toVisit = toVisit.Begin();
    while (walker_for_toVisit){
        if (!checkExist(visited, walker_for_toVisit->_item.getStadiumName())){
            list_for_checkExist.InsertAfter(stadiumNode("", walker_for_toVisit->_item.getStadiumName(), 0),
                                            list_for_checkExist.End());
        }
        walker_for_toVisit = walker_for_toVisit->next;
    }


    if (visited.isEmpty()){
        while (walker_result){
            if (walker_result->_item._src == walker_result->_item._des){
                returnMe = walker_result->_item;
                break;
            }
            walker_result = walker_result->next;
        }
    }else{
        while (walker_result){
            if (checkExist(list_for_checkExist, walker_result->_item._des) &&
                    walker_result->_item._distancetoSrc < shortest &&
                    walker_result->_item._src != walker_result->_item._des){
                shortest = walker_result->_item._distancetoSrc;
                returnMe = walker_result->_item;
            }
            walker_result = walker_result->next;
        }
    }
    return returnMe;
}

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
