/***************************************
 * AUTHOR                : Justin Kuhn, Anna Ma, Kevin Prada
 * Project 2             : I Love Baseball
 * CLASS                 : CS8
 * SECTION               : MW 9:45-11:10AM TTH 9:45-11:50AM
 * Due Date              : 12/5/19
 * *************************************/

#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H
#include <iostream>
#include <cassert>
using namespace std;

/*******************************************************************
 *  node struct
 *     This structure represents a templated node in a linked list.
 * *****************************************************************/
template <typename ITEM_TYPE>
struct node
{
public:
    // constructor calls default for template obj and next to null
    node(){
        next = NULL;
        _item = ITEM_TYPE();
    }
    // constructor sets obj and  sets next to null
    node(ITEM_TYPE item){
        next = NULL;
        _item = item;
    }

    ITEM_TYPE _item;        //ATT - item in list
    node<ITEM_TYPE>* next;  //ATT - next item in list


};

/*******************************************************************
 *  node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head,
 *                           ITEM_TYPE key);
 *     This searches the list for the key and returns a pointer to
 *          the relevant node.
 * *****************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head,  //IN - list head
                            ITEM_TYPE key);         //IN - val to search for

/*******************************************************************
 *  node<ITEM_TYPE>* _PreviousNode(node<ITEM_TYPE>* head,
 *                             node<ITEM_TYPE>* prevToThis);
 *     This returns a pointer to the previous node.
 * *****************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _PreviousNode(node<ITEM_TYPE>* head,       //IN - list head
                              node<ITEM_TYPE>* prevToThis); //IN - prev pointer

/*******************************************************************
 *  node<ITEM_TYPE>* _InsertHead(node<ITEM_TYPE> *&head,
 *                           ITEM_TYPE insertThis);
 *     This returns a pointer to a node inserted at the head of list.
 * *****************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertHead(node<ITEM_TYPE> *&head,     //IN - list head
                            ITEM_TYPE insertThis);       //IN - val to insert

/*******************************************************************
 *  node<ITEM_TYPE>* _InsertAfter(
 *                             node<ITEM_TYPE> *afterThis,
 *                           ITEM_TYPE insertThis);
 *     This inserts the value after the pointer and returns a pointer to
 *      the inserted object.
 * *****************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertAfter(
                              node<ITEM_TYPE> *afterThis,   //IN - node ptr
                             ITEM_TYPE insertThis);         //IN - val to ins

/*******************************************************************
 *  node<ITEM_TYPE>* _InsertBefore(node<ITEM_TYPE>*& head,
 *                             node<ITEM_TYPE>* beforeThis,
 *                             ITEM_TYPE insertThis);
 *     This inserts the value before the pointer and returns a pointer to
 *      the inserted object.
 * *****************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertBefore(node<ITEM_TYPE>*& head,      //IN - list head
                              node<ITEM_TYPE>* beforeThis,  //IN - ins before
                              ITEM_TYPE insertThis);        //IN - val to ins
/*******************************************************************
 *  ITEM_TYPE _DeleteNode(node<ITEM_TYPE>*&head,
 *                    node<ITEM_TYPE>* deleteThis);
 *
 *     This deletes the node at the passed pointer.
 * *****************************************************************/
template <typename ITEM_TYPE>
ITEM_TYPE _DeleteNode(node<ITEM_TYPE>*&head,                 //IN - list head
                     node<ITEM_TYPE>* deleteThis);           //IN - ptr to del

/*******************************************************************
 *  node<ITEM_TYPE>* _CopyList(node<ITEM_TYPE>* head);
 *     This returns a copy of the passed list.
 * *****************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _CopyList(node<ITEM_TYPE>* head);       //IN - list head

/*******************************************************************
 *  void _ClearList(node<ITEM_TYPE>*& head);
 *     This deletes all of the nodes from the list
 * *****************************************************************/
template <typename ITEM_TYPE>
void _ClearList(node<ITEM_TYPE>*& head);                 //IN - list head

/*******************************************************************
 *  ITEM_TYPE& At(node<ITEM_TYPE>* head, int pos);
 *     This returns a reference to the item at the position.
 * *****************************************************************/
template <typename ITEM_TYPE>
ITEM_TYPE& At(node<ITEM_TYPE>* head,         //IN - list head
              int pos);                      //IN - position to ret val

/*******************************************************************
 *  node<ITEM_TYPE>* _InsertSorted(node<ITEM_TYPE>* &head,
 *                            ITEM_TYPE item,
 *                            bool ascending=true);
 *     This inserts a value into a sorted list in the proper position and
 *      order.
 * *****************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertSorted(node<ITEM_TYPE>* &head,    //IN - list head
                             ITEM_TYPE item,              //IN - val to ins
                             bool ascending=true);        //IN - how to sort
/*******************************************************************
 *      node<ITEM_TYPE>* InsertSorted_and_add(node<ITEM_TYPE>* &head,
 *                                         ITEM_TYPE item,
 *                                         bool ascending=true);
 *
 *     This inserts a value into a sorted list in the proper position and
 *      order. It adds it to the list if it is a duplicate.
 * *****************************************************************/
template <typename ITEM_TYPE>
    node<ITEM_TYPE>* InsertSorted_and_add(
                                    node<ITEM_TYPE>* &head,//IN - list head
                                    ITEM_TYPE item,        //IN - val to ins
                                    bool ascending=true);  //IN - how to sort


/*******************************************************************
 *  node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* head,
 *                            ITEM_TYPE item, bool unique,
 *                            bool ascending=true);
 *     This returns a pointer to the node after which this sorted value
 *      will be placed.
 * *****************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* head,        //IN - list head
                              ITEM_TYPE item,                //IN - val to ins
                               bool unique,                  //IN - if unique
                              bool ascending=true);          //IN - how to sort


/*******************************************************************
 *  node<ITEM_TYPE>* LastNode(node<ITEM_TYPE>* head);
 *     This returns the last node in the list.
 * *****************************************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* LastNode(node<ITEM_TYPE>* head);          //IN - list head


/***************************************
 *  node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head, ITEM_TYPE key){
 *
 * --------------------------------------------------------------------
 *  This returns a pointer to a value in the list matching the key.
 * --------------------------------------------------------------------
 *  INPUT:
 *      head - front of list
 *      key - value to search for
 * OUTPUT:
 *      pointer to node in list
 *
 * *************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head,  //IN - list head
                            ITEM_TYPE key){         //IN - val to search for
    assert(head != NULL);
    node<ITEM_TYPE> * walker = head;                //CALC - temp pointer
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

/***************************************
 * node<ITEM_TYPE>* _InsertHead(node<ITEM_TYPE> *&head, ITEM_TYPE insertThis){
 *
 * --------------------------------------------------------------------
 *  This returns a pointer to a value inserted at the head of the list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      head - front of list
 *      insertThis - value to insert
 * OUTPUT:
 *      pointer to  inserted node in list
 *
 * *************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertHead(node<ITEM_TYPE> *&head,     //IN - list head
                             ITEM_TYPE insertThis){      //IN - val to insert
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(insertThis);//CALC - new node
    temp->next = head;
    head= temp;
    return head;
}

/***************************************
 * node<ITEM_TYPE>* _InsertAfter(
 *                      node<ITEM_TYPE> *afterThis, ITEM_TYPE insertThis){ *
 * --------------------------------------------------------------------
 *  This returns a pointer to a value inserted after the passed pointer
 * --------------------------------------------------------------------
 *  INPUT:
 *      afterThis - insert the value aftert this pointer
 *      insertThis - value to insert
 * OUTPUT:
 *      pointer to  inserted node in list
 *
 * *************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertAfter(
                              node<ITEM_TYPE> *afterThis,  //IN - ptr
                              ITEM_TYPE insertThis){       //IN - ins after ptr
    // calls insert head and use afterthis-> next as the head
    return _InsertHead(afterThis->next, insertThis);
}

/***************************************
 * node<ITEM_TYPE>* _InsertBefore(node<ITEM_TYPE>*& head,
 *                             node<ITEM_TYPE>* beforeThis,
 *                             ITEM_TYPE insertThis){
 * --------------------------------------------------------------------
 *   Finds the previous node using _PreviousNode function, then use insert head
       unction with prev->next as the head. if prev == nullptr i.e. if it is a
       empty list, call insert head directly
 * --------------------------------------------------------------------
 *  INPUT:
 *      head - pointer to head of the list
 *      afterThis - insert the value before this pointer
 *      insertThis - value to insert
 * OUTPUT:
 *      pointer to  inserted node in list
 *
 * *************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertBefore(node<ITEM_TYPE>*& head,       //IN - list head
                               node<ITEM_TYPE>* beforeThis,  //IN - ptr
                              ITEM_TYPE insertThis){         //IN - ins be4 ptr
    node<ITEM_TYPE> *prev = _PreviousNode(head, beforeThis);
    if (prev == nullptr){
        return _InsertHead(head, insertThis);
    }
    return _InsertHead(prev->next, insertThis);
}

/***************************************
 * node<ITEM_TYPE>* _PreviousNode(node<ITEM_TYPE>* head,
 *                                          node<ITEM_TYPE>* prevToThis){
 *
 * --------------------------------------------------------------------
 *  This returns a pointer to the node previous to the one passed
 * --------------------------------------------------------------------
 *  INPUT:
 *      head - pointer to head of the list
 *      prevtoThis - return pointer to val previous to this
 * OUTPUT:
 *      pointer to node before passed node
 *
 * *************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _PreviousNode(node<ITEM_TYPE>* head,        // IN - list head
                               node<ITEM_TYPE>* prevToThis){ // IN - ptr
    // use a walker to compare if the node that the current node is pointing to
    // is equal to prevToThis. walker stops at that point and return that point
    node<ITEM_TYPE> *walker = head;         // CALC - to traverse
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

/***************************************
 * ITEM_TYPE _DeleteNode(node<ITEM_TYPE>*&head, node<ITEM_TYPE>* deleteThis){
 *
 * --------------------------------------------------------------------
 *  This deletes the passed node from the list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      head - pointer to head of the list
 *      deleteThis - delete this node
 * OUTPUT:
 *      item inside node that is deleted
 *
 * *************************************/
template <typename ITEM_TYPE>
ITEM_TYPE _DeleteNode(node<ITEM_TYPE>*&head,            // IN - list head
                      node<ITEM_TYPE>* deleteThis){     // IN - ptr to delete
    //first find the previous node to the node that will be deleted, make that
    // node point to the next node of the deleting node, delete the node.
    assert(head != NULL);
    assert(deleteThis!=NULL);
    ITEM_TYPE temp = deleteThis->_item;                 // CALC - object deleted
    node <ITEM_TYPE> *prev
            = _PreviousNode(head,deleteThis);           // CALC - left shift
    if (prev == nullptr){
        head= deleteThis->next;
        delete deleteThis;
        return temp;
    }
    prev->next = deleteThis->next;
    delete deleteThis;
    return temp;
}


/***************************************
 * node<ITEM_TYPE>* _CopyList(node<ITEM_TYPE>* head)
 *
 * --------------------------------------------------------------------
 *  This returns a copy of the passed list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      head - pointer to head of the list
 * OUTPUT:
 *      pointer to head of a list that is copy of passed list
 *
 * *************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _CopyList(node<ITEM_TYPE>* head){ // IN - list head
    // set a walker walking through the old list, set a walker to the new list,
    // walker through each element in the old list and append it to the new list
    node<ITEM_TYPE> *result = NULL;     // CALC - result pointer
    node<ITEM_TYPE> *result_walker;     // IN - to traverse
    node<ITEM_TYPE> *walker = head;     // IN - ptr to head
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

/***************************************
 * void _ClearList(node<ITEM_TYPE>*& head){
 *
 * --------------------------------------------------------------------
 *  This deletes all of the nodes in the list by setting the by deallocating
 *      each node and setting the pointer to NULL.
 * --------------------------------------------------------------------
 *  INPUT:
 *      head - pointer to head of the list
 * OUTPUT:
 *      Nothing
 *
 * *************************************/
template <typename ITEM_TYPE>
void _ClearList(node<ITEM_TYPE>*& head){ // IN - list head
    // call the function to delete a single node, while list is not empty, keep
    // deleting the head node, at the end, set head to node pointer
    while (head != NULL){
        _DeleteNode(head,head);
    }
    head = NULL;
}

/***************************************
 * ITEM_TYPE& At(node<ITEM_TYPE>* head, int pos)
 *
 * --------------------------------------------------------------------
 *  This returns a reference to the item in a list at the passed position.
 * --------------------------------------------------------------------
 *  INPUT:
 *      head - pointer to head of the list
 *      pos - position of the list to remove
 * OUTPUT:
 *      returns reference to an object at the position
 *
 * *************************************/
template <typename ITEM_TYPE>
ITEM_TYPE& At(node<ITEM_TYPE>* head,        // IN - list head
              int pos){                     // IN - list position
    // use a counter to counter to the particular position
    int counter = 0;
    node <ITEM_TYPE> * w=head;              // CALC - to traverse
    while (w != NULL && counter != pos){
        w = w->next;
        counter++;
    }
    return w->_item;
}

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
/***************************************
 * node<ITEM_TYPE>* InsertSorted_and_add(node<ITEM_TYPE>* &head,
 *                                     ITEM_TYPE item,
 *                                     bool ascending){
 *
 * --------------------------------------------------------------------
 *  This returns a reference to a value inserted to a sorted list.
 *      Adds if it already exists.
 * --------------------------------------------------------------------
 *  INPUT:
 *      head - pointer to head of the list
 *      item - item to insert
 *      ascending - if the sort is in ascending order
 * OUTPUT:
 *      returns reference to the inserted object
 *
 * *************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted_and_add(node<ITEM_TYPE>* &head, // IN - list head
                                      ITEM_TYPE item,         // IN - val ins
                                      bool ascending){        // IN - sort type
    node<ITEM_TYPE>*ptr
            = WhereThisGoes(head,item,true,ascending);  // CALC - helper
    if (ptr == nullptr || head == NULL){
        return _InsertHead(head,item);
    }
    if (ptr->_item == item){
        ptr->_item = ptr->_item + item;
        return ptr;
    }
        return _InsertAfter(ptr, item);
}

/***************************************
 * node<ITEM_TYPE>* _InsertSorted(node<ITEM_TYPE>* &head,ITEM_TYPE target,
 *                                      bool ascending){
 *
 * --------------------------------------------------------------------
 *  This returns a reference to a value inserted into a list that is
 *      already sorted in a ascending or descending order.
 * --------------------------------------------------------------------
 *  INPUT:
 *      head - pointer to head of the list
 *      target - item to insert
 *      ascending - if the sort is in ascending order
 * OUTPUT:
 *      returns reference to the inserted object
 *
 * *************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertSorted(node<ITEM_TYPE>* &head,  // IN - list head
                               ITEM_TYPE target,        // IN - val to ins
                               bool ascending){         // IN - sort type
    // this function finds where the node should go, then if it is a empty list
    // insert it at head, else use insert after
    node<ITEM_TYPE>* ptr
            =WhereThisGoes(head,target,false,ascending); //CALC - helper
    if (ptr == NULL || head == NULL){
        return _InsertHead(head,target);
    }
        return _InsertAfter(ptr, target);
}

/***************************************
 * node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* head, ITEM_TYPE item,
 *                              bool unique,bool ascending){
 *
 * --------------------------------------------------------------------
 * First check if item is greater than last node, if yes place at the end,
 *    then check if less than head, lastly loop through all the elements
 * --------------------------------------------------------------------
 *  INPUT:
 *      head - pointer to head of the list
 *      item - item to insert
 *      unique - if the item is unique
 *      ascending - if the sort is in ascending order
 * OUTPUT:
 *      returns reference to the inserted object
 *
 * *************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* head, // IN - list head
                               ITEM_TYPE item,        // IN - val to ins
                               bool unique,           // IN - if unique
                               bool ascending){       // IN - sort type
    node<ITEM_TYPE>* w = head;                  // CALC - head traverse
    node<ITEM_TYPE> * nextItem = head ->next;   // CALC - check ahead
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

/***************************************
 * node<ITEM_TYPE>* LastNode(node<ITEM_TYPE>* head){
 *
 * --------------------------------------------------------------------
 *  This returns a reference to the last node in a list given the head of
 *      a list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      head - pointer to head of the list
 * OUTPUT:
 *      returns reference to the last node of the list
 *
 * *************************************/
template <typename ITEM_TYPE>
node<ITEM_TYPE>* LastNode(node<ITEM_TYPE>* head){ // IN - list head
    node<ITEM_TYPE>* w = head;                    // IN - to traverse
    if (head == NULL){
        return head;
    }
    while (w->next != NULL){
        w = w->next;
    }
    return w;
}

#endif // LINKED_LIST_FUNCTIONS_H
