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

int graph::getedge(string stadiumSrc, string stadiumDes){

    node<List<stadiumNode>>* w = this->adjList.Begin();
    node<stadiumNode>* w2 = nullptr;
    while (w != nullptr){
        if (w->_item.Begin()->_item._src == stadiumSrc){
            w2 = w->_item.Begin();
            while (w2 != nullptr){
                if (w2->_item._des == stadiumDes){
                    return w2->_item._distancetoSrc;
                }
                w2 = w2->next;
            }
        }
        w = w->next;
    }
    return -1;
}

List<stadium> graph::getStadiumList() const{
    return this->stadiums;
}

void graph::addStadium(stadium s){
    // avoid double adding
    //    assert(getStadiumInfo(s.getStadiumName())==stadium());
    if(!(getStadiumInfo(s.getStadiumName()) == stadium())){
        return;
    }
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
    // the stadiums must exist
    //    assert(getStadiumInfo(src).getStadiumName() == src);
    //    assert(getStadiumInfo(des).getStadiumName() == des);
    if(getStadiumInfo(src).getStadiumName() != src ||
            getStadiumInfo(des).getStadiumName() != des){
        return;
    }

    node<List<stadiumNode>>* w = this->adjList.Begin();
    stadiumNode edge =stadiumNode(src, des, distance);
    stadiumNode edge2 = stadiumNode(des, src, distance);

    while (w != nullptr){
        if (w->_item.Begin()->_item._src == src){
            w->_item.InsertAfter(edge, w->_item.End());
        }
        if (w->_item.Begin()->_item._src == des){
            w->_item.InsertAfter(edge2, w->_item.End());
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


