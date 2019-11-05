#include "adjlist.h"

ListofStadiumList::ListofStadiumList(){
    _head = nullptr;
}

ListofStadiumList::~ListofStadiumList(){
    stadiumList* temp = nullptr;
    while (this->_head){
        this->_head->deleteAllNodes();
        temp = this->_head->next;
        this->_head = this->_head->next;
    }
}

ListofStadiumList::ListofStadiumList(const ListofStadiumList& other){
    *this = other;
}

ListofStadiumList& ListofStadiumList::operator =(const ListofStadiumList& other){
    stadiumList* w = other._head;

    while(w != nullptr){
        this->_head = w;
        this->_head = this->_head->next;
        w = w->next;
    }

    return *this;
}

//GETTERS
stadium* ListofStadiumList::getStadium(string name){
    cout << "hi" <<endl;
    cout << this->_head->item->stadium.getStadiumName()<<endl;
    stadium* returnMe = nullptr;
    stadiumList* w = this->_head;
    while (w){
        cout << "HII  " <<endl;
        if (w->item->stadium.getStadiumName() == name){
            cout << "stadium name: " << w->item->stadium.getStadiumName() <<endl;
            returnMe = &w->item->stadium;
            return returnMe;
        }
    }
    return returnMe;
}

int ListofStadiumList::getDistance(stadium src, stadium des){
    stadiumList* w = this->_head;
    stadiumNode* w2 = w->item;

    while (w){
        if (w->item->stadium == src){
            while (w2){
                if (w2->stadium == des){
                    return w2->_distanceToSrc;
                }
                w2 = w2->next;
            }
            w = w->next;
        }
    }
    return -1;
}

//SETTERS
void ListofStadiumList::addStadium(stadium s){
    stadiumList* w = this->_head;
    if (!w){
        w = new stadiumList(stadiumNode(s,0));
        cout << this->_head->item->stadium.getTeamName() <<endl;
        return;
    }
    while (w){
        if(w->next == nullptr){
            w->next = new stadiumList(stadiumNode(s, 0));
            w->next->next = nullptr;
            return;
        }else{
            w = w->next;
        }
    }

}

void ListofStadiumList::addEdge(stadium src, stadium des, int distance){
    bool alreadyexist = false;
    stadiumList* w = this->_head;
    stadiumNode* w2 = w->item;

    while (w){
        if (w->item->stadium == src){
            while (w2){
                if (w2->stadium == des){
                    alreadyexist = true;
                    break;
                }
                if (w2->next == nullptr){
                    w2->next = new stadiumNode(des, distance);
                    alreadyexist = true;
                    break;
                }
                w2 = w2->next;
            }
            if (alreadyexist)
                break;
            w = w->next;
        }
    }

}

bool ListofStadiumList::removeStadium(string name){
    stadiumList* w = this->_head;
    stadiumList* toDelete = nullptr;
    while(w){
        if (w->next->item->stadium.getStadiumName() == name){
            toDelete = w->next;
            w->next = toDelete->next;
            toDelete->deleteAllNodes();
            return true;
        }
        w = w->next;
    }
    return false;
}

bool ListofStadiumList::removeEdge(string src, string des){
    stadiumList* w = this->_head;
    stadiumNode* w2 = w->item;
    stadiumNode* toDelete = nullptr;

    while (w){
        if (w->item->stadium.getStadiumName() ==src){
            while (w2){
                if (w2->next->stadium.getStadiumName() ==des){
                    toDelete = w2->next;
                    w2->next = toDelete->next;
                    delete toDelete;
                    return true;
                }
                w2 = w2->next;
            }
        }
        w = w->next;
    }
    return false;
}
