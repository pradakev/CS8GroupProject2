#include "graph.h"

graph::graph(){
    this->stadiumList = nullptr;
}

graph::~graph(){
    cout << "destructor fired: " << endl;
    node<stadiumNode>* temp = nullptr;
    while (this->stadiumList != nullptr){
        temp = this->stadiumList->_item;
        _ClearList(temp);
        this->stadiumList = this->stadiumList->next;
    }
    _ClearList(this->stadiumList);
}

stadium graph::getStadium(string stadiumName){

    while (this->stadiumList != nullptr){
        if (this->stadiumList->_item->_item._s.getStadiumName() == stadiumName){
            return this->stadiumList->_item->_item._s;
        }else{
            this->stadiumList = this->stadiumList->next;
        }
    }
    return stadium();
}

int graph::getedge(string stadiumSrc, string stadiumDes){

    while (this->stadiumList != nullptr){
        if (this->stadiumList->_item->_item._s.getStadiumName() == stadiumSrc){
            while (this->stadiumList->_item != nullptr){
                if (this->stadiumList->_item->_item._s.getStadiumName() == stadiumDes){
                    return this->stadiumList->_item->_item._distancetoSrc;
                }
                this->stadiumList->_item = this->stadiumList->_item->next;
            }
        }
        this->stadiumList = this->stadiumList->next;
    }
    return -1;
}

void graph::addStadium(stadium s){
    stadiumNode toAdd = stadiumNode(s,0);
    node<stadiumNode> *newList = new node<stadiumNode>;
    _InsertHead(newList, toAdd);

    if (this->stadiumList == nullptr){
        _InsertHead(this->stadiumList, newList);
    }else{
        _InsertAfter(LastNode(this->stadiumList),newList);
    }
}

void graph::addEdge(stadium src, stadium des, int distance){
    stadiumNode edge =stadiumNode(des, distance);

    while (this->stadiumList != nullptr){
        if (this->stadiumList->_item->_item._s == src){
            _InsertAfter(LastNode(this->stadiumList->_item), edge);
            return;
        }else{
            this->stadiumList = this->stadiumList->next;
        }
    }

}

