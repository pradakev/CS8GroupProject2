#include "graph.h"

graph::graph(){}

graph::~graph(){}

stadium graph::getStadium(string stadiumName){

    node<List<stadiumNode>>* w = this->stadiumList.Begin();
    while (w != nullptr){
        if (w->_item.Begin()->_item._s.getStadiumName() == stadiumName){
            return w->_item.Begin()->_item._s;
        }else{
            w = w->next;
        }
    }
    return stadium();
}

int graph::getedge(string stadiumSrc, string stadiumDes){

    node<List<stadiumNode>>* w = this->stadiumList.Begin();
    node<stadiumNode>* w2 = nullptr;
    while (w != nullptr){
        if (w->_item.Begin()->_item._s.getStadiumName() == stadiumSrc){
            w2 = w->_item.Begin();
            while (w2 != nullptr){
                if (w2->_item._s.getStadiumName() == stadiumDes){
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
    List<stadiumNode> newList;
    stadiumNode toAdd = stadiumNode(s,0);
    newList.InsertHead(toAdd);
    this->stadiumList.InsertAfter(newList, this->stadiumList.End());


}

void graph::addEdge(stadium src, stadium des, int distance){
    node<List<stadiumNode>>* w = this->stadiumList.Begin();
    stadiumNode edge =stadiumNode(des, distance);

    while (w != nullptr){
        if (w->_item.Begin()->_item._s == src){
            w->_item.InsertAfter(edge, w->_item.End());
        }
        w =w->next;
    }

}

