#ifndef ADJLIST_H
#define ADJLIST_H
#include <iostream>
#include <stadium.h>
using namespace std;

struct stadiumNode{

    stadiumNode(stadium s, int distance){
        stadium = s;
        _distanceToSrc = distance;
    }

    stadiumNode* next;

    stadium stadium;
    int _distanceToSrc;

};

struct stadiumList{
    friend stadiumNode;

    stadiumList(){
        item = nullptr;
    }

    stadiumList(stadiumNode s){
        item = new stadiumNode(s.stadium, s._distanceToSrc);
    }

    ~stadiumList(){
        deleteAllNodes();
    }

    stadiumList(const stadiumList& other){
        *this = other;
    }

    stadiumList& operator =(const stadiumList& other){
        stadiumNode* w = other.item;
        while (w != nullptr){
            this->item = w;
            w = w->next;
            this->item = this->item->next;
        }
        return *this;
    }

    void deleteAllNodes(){
        stadiumNode* temp = nullptr;
        while (this->item){
            temp = this->item->next;
            delete this->item;
            this->item = this->item->next;
        }
    }

    stadiumNode* item;
    stadiumList* next;
};

class ListofStadiumList
{
public:

    friend stadiumList;

    ListofStadiumList();
    ~ListofStadiumList();
    ListofStadiumList(const ListofStadiumList& other);
    ListofStadiumList& operator =(const ListofStadiumList& other);

    //GETTERS
    stadium* getStadium(string name);
    int getDistance(stadium src, stadium des);

    //SETTERS
    void addStadium(stadium s);
    void addEdge(stadium src, stadium des, int distance);
    bool removeStadium(string name);
    bool removeEdge(string src, string des);



    // testing functions

    void print(){
//        stadiumNode* nodew = nullptr;
        while (this->_head){
            cout << "head stadium: " << this->_head->item->stadium.getStadiumName();
//            nodew = this->_head->src;
//            cout << "edges: "<<endl;
//            while (nodew){
//                cout << nodew->des.getStadiumName();
//                cout << endl;
//                nodew = nodew->next;
//            }
            this->_head = this->_head->next;
        }
    }

private:
    stadiumList* _head;
};

#endif // ADJLIST_H
