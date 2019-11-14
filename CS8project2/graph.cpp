#include "graph.h"

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

void graph::addStadium(stadium s){
    // avoid double adding
//    assert(getStadiumInfo(s.getStadiumName())==stadium());
    if(!(getStadiumInfo(s.getStadiumName()) == stadium())){
        return;
    }
    // inserts into stadium list
    this->stadiums.InsertAfter(s,this->stadiums.End());

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

    while (w != nullptr){
        if (w->_item.Begin()->_item._src == src){
            w->_item.InsertAfter(edge, w->_item.End());
        }
        w =w->next;
    }

}

List<stadiumNode> graph::shortestPath_TwoCities(string src, string des){

}

List<stadiumNode> graph::shortestPath(List<stadium>){

}

List<stadium> graph::getAmericanLeagueStadiums(){

}

List<stadium> graph::getNationalLeagueStadiums(){

}

List<stadium> graph::getStadiumWithGrassField(){

}

List<stadium> graph::sort(string LeagueType,bool grassSurface,bool byTeamName,
                   bool byDate){

}

