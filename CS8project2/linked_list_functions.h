#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H
#include <iostream>
#include <cassert>
using namespace std;

template <typename ITEM_TYPE>
struct node
{
public:
    node(){
        next = NULL;
        _item = ITEM_TYPE();
    }
    node(ITEM_TYPE item){
        next = NULL;
        _item = item;
    }

    ITEM_TYPE _item;
    node<ITEM_TYPE>* next;


};

template <typename ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head,          //return ptr to key or NULL
                            ITEM_TYPE key);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _PreviousNode(node<ITEM_TYPE>* head,        //ptr to previous node
                              node<ITEM_TYPE>* prevToThis);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertHead(node<ITEM_TYPE> *&head,         //insert at the head of list
                            ITEM_TYPE insertThis);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertAfter(
                              node<ITEM_TYPE> *afterThis,    //insert after ptr
                             ITEM_TYPE insertThis);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertBefore(node<ITEM_TYPE>*& head,       //insert before ptr
                              node<ITEM_TYPE>* beforeThis,
                              ITEM_TYPE insertThis);

template <typename ITEM_TYPE>
ITEM_TYPE _DeleteNode(node<ITEM_TYPE>*&head,                 //delete, return item
                     node<ITEM_TYPE>* deleteThis);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _CopyList(node<ITEM_TYPE>* head);           //duplicate the list...

template <typename ITEM_TYPE>
void _ClearList(node<ITEM_TYPE>*& head);                     //delete all the nodes

template <typename ITEM_TYPE>
ITEM_TYPE& At(node<ITEM_TYPE>* head, int pos);              //_item at this position

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertSorted(node<ITEM_TYPE>* &head,       //insert
                             ITEM_TYPE item,
                             bool ascending=true);

template <typename ITEM_TYPE>
    node<ITEM_TYPE>* InsertSorted_and_add(node<ITEM_TYPE>* &head, //insert or add if a dup
                                          ITEM_TYPE item,
                                          bool ascending=true);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* head,         //node after which this
                              ITEM_TYPE item, bool unique,                //    item goes
                              bool ascending=true);          //order: 0 ascending


template <typename ITEM_TYPE>
node<ITEM_TYPE>* LastNode(node<ITEM_TYPE>* head);            //Last Node in the list


template <typename ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head, ITEM_TYPE key){
    assert(head != NULL);
    node<ITEM_TYPE> * walker = head;
    // if there is only 1 item in the list, this will check the item inside where
    // head is pointing
    if (head->_item == key)
        return head;
    // loop through the entire list
    while (walker != NULL){
        if (key == walker->_item)
            return walker;
        walker = walker->next;
    }
    return NULL;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertHead(node<ITEM_TYPE> *&head, ITEM_TYPE insertThis){
    // create a new node -> make node point to where head is pointing -> point head
    // to the new node
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(insertThis);
    temp->next = head;
    head= temp;
    return head;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertAfter(
                              node<ITEM_TYPE> *afterThis, ITEM_TYPE insertThis){
    // calls insert head and use afterthis-> next as the head
    return _InsertHead(afterThis->next, insertThis);
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertBefore(node<ITEM_TYPE>*& head, node<ITEM_TYPE>* beforeThis,
                              ITEM_TYPE insertThis){
    // finds the previous node using _PreviousNode function, then use insert head
    // function with prev->next as the head. if prev == nullptr i.e. if it is a
    // empty list, call insert head directly
    node<ITEM_TYPE> *prev = _PreviousNode(head, beforeThis);
    if (prev == nullptr){
        return _InsertHead(head, insertThis);
    }
    return _InsertHead(prev->next, insertThis);
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _PreviousNode(node<ITEM_TYPE>* head,node<ITEM_TYPE>* prevToThis){
    // use a walker to compare if the node that the current node is pointing to
    // is equal to prevToThis. walker stops at that point and return that point
    node<ITEM_TYPE> *walker = head;
    assert(walker != NULL);
    while (walker!= NULL){
        if (head == prevToThis){
            return NULL;
        }
        if (walker ->next == prevToThis){
            return walker;
        }
        walker = walker ->next;
    }
    assert(walker != NULL);
    return NULL;
}

template <typename ITEM_TYPE>
ITEM_TYPE _DeleteNode(node<ITEM_TYPE>*&head, node<ITEM_TYPE>* deleteThis){
    //first find the previous node to the node that will be deleted, make that
    // node point to the next node of the deleting node, delete the node.
    assert(head != NULL);
    assert(deleteThis!=NULL);
    ITEM_TYPE temp = deleteThis->_item;
    node <ITEM_TYPE> *prev = _PreviousNode(head,deleteThis);
    if (prev == nullptr){
        head= deleteThis->next;
        delete deleteThis;
        return temp;
    }
    prev->next = deleteThis->next;
    delete deleteThis;
    return temp;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _CopyList(node<ITEM_TYPE>* head){
    // set a walker walking through the old list, set a walker to the new list,
    // walker through each element in the old list and append it to the new list
    node<ITEM_TYPE> *result = NULL;
    node<ITEM_TYPE> *result_walker;
    node<ITEM_TYPE> *walker = head;
    while (walker != NULL){

        if (result == NULL){
            result_walker = _InsertHead(result, walker->_item);
        }else{
            result_walker = _InsertAfter(result_walker, walker->_item);
        }
        walker = walker->next;
    }
    return result;

}

template <typename ITEM_TYPE>
void _ClearList(node<ITEM_TYPE>*& head){
    // call the function to delete a single node, while list is not empty, keep
    // deleting the head node, at the end, set head to node pointer
    while (head != NULL){
        _DeleteNode(head,head);
    }
    head = NULL;
}

template <typename ITEM_TYPE>
ITEM_TYPE& At(node<ITEM_TYPE>* head, int pos){
    // use a counter to counter to the particular position
    int counter = 0;
    node <ITEM_TYPE> * w=head;
    while (w != NULL && counter != pos){
        w = w->next;
        counter++;
    }
    return w->_item;
}

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted_and_add(node<ITEM_TYPE>* &head, //insert or add if a dup
                                      ITEM_TYPE item,
                                      bool ascending){
    node<ITEM_TYPE>*ptr = WhereThisGoes(head,item,true,ascending);
    if (ptr == nullptr || head == NULL){
        return _InsertHead(head,item);
    }
    if (ptr->_item == item){
        ptr->_item = ptr->_item + item;
        return ptr;
    }
        return _InsertAfter(ptr, item);
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertSorted(node<ITEM_TYPE>* &head,ITEM_TYPE target, bool ascending){
    // this function finds where the node should go, then if it is a empty list
    // insert it at head, else use insert after
    node<ITEM_TYPE>* ptr =WhereThisGoes(head,target,false,ascending);
    if (ptr == NULL || head == NULL){
        return _InsertHead(head,target);
    }
        return _InsertAfter(ptr, target);
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* head, ITEM_TYPE item,
                               bool unique,bool ascending){
    // first check if item is greater than last node, if yes place at the end,
    // then check if less than head, lastly loop through all the elements
    node<ITEM_TYPE>* w = head;
    node<ITEM_TYPE> * nextItem = head ->next;
    if (ascending == true){
        if (item > LastNode(head)->_item){
            return LastNode(head);
        }
        if (item == head->_item && unique == true){
            return head;
        }
        if (item < head->_item){
            return nullptr;
        }
        while (item > nextItem->_item && w != NULL){
            nextItem = nextItem->next;
            w = w->next;
        }
    }

    if (ascending == false) {
        if (item < LastNode(head)->_item){
            return LastNode(head);
        }
        if (item == head->_item && unique == true){
            return head;
        }
        if (item > head->_item){
            return nullptr;
        }
        while (item <= nextItem->_item && w != NULL){
            nextItem = nextItem->next;
            w = w->next;
        }
    }
    return w;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* LastNode(node<ITEM_TYPE>* head){
    node<ITEM_TYPE>* w = head;
    if (head == NULL){
        return head;
    }
    while (w->next != NULL){
        w = w->next;
    }
    return w;
}

#endif // LINKED_LIST_FUNCTIONS_H
