#ifndef ADJLIST_H
#define ADJLIST_H
#include <iostream>
#include <stadium.h>
using namespace std;

struct stadiumNode{
    stadium s;
    int distanceToHead;
    stadiumNode* next;
};

struct stadiumList{
    stadiumNode* head;
};

class adjlist
{
public:
    adjlist();
    ~adjlist();
    adjlist(const adjlist& other);
    adjlist& operator =(const adjlist& other);

    //GETTERS
    stadium getStadium(string name);
    int getDistance(stadium src, stadium des);

    //SETTERS
    void addStadium(stadium s);
    void addEdge(stadium src, stadium des);
    void removeStadium(stadium s);
    void removeEdge(stadium src, stadium des);

private:
    stadiumList* _s;
};

#endif // ADJLIST_H
