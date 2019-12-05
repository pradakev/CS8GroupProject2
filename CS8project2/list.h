/***************************************
 * AUTHOR                : Justin Kuhn, Anna Ma, Kevin Prada
 * Project 2             : I Love Baseball
 * CLASS                 : CS8
 * SECTION               : MW 9:45-11:10AM TTH 9:45-11:50AM
 * Due Date              : 12/5/19
 * *************************************/

#ifndef LIST_H
#define LIST_H
#include "linked_list_functions.h"

/*******************************************************************
 *  List class
 *     This class represents a templated linked list with typical linked
 *      list operations
 * *****************************************************************/
template <class T>
class List
{
public:

    /*******************************************************************
     *  List();
     *     This sets the head to NULL
     * *****************************************************************/
    List();

    /*******************************************************************
     *  ~List();
     *     This destroys the list and deallocates nodes.
     * *****************************************************************/
    ~List();
    /*******************************************************************
     *  List(const List<T> &copyThis);
     *     This is a copy constructor
     * *****************************************************************/
    List(const List<T> &copyThis); //IN - list to copy
    /*******************************************************************
     *  List& operator =(const List& RHS){
     *     This assignment operator copies the RHS list to this list.
     * *****************************************************************/
    List& operator =(const List& RHS){  //IN - list to copy
        head = _CopyList(RHS.head);
        return *this;
    }
    /*******************************************************************
     *  bool operator ==(const List& rhs){
     *     This checks of the RHS list is the same as the calling list.
     * *****************************************************************/
    bool operator ==(const List& rhs){  //IN - list to compare
        node<T>* w = this->head;        // CALC - to traverse
        node<T>* w2 = rhs.head;         // CALC - to traverse rhs

        while(w || w2){
            if (!(w->_item == w2->_item)){
                return false;
            }
            w = w->next;
            w2 = w2->next;
        }
        return true;
    }

    /*******************************************************************
     *  bool isEmpty() const;
     *     This checks of the list is empty
     * *****************************************************************/
    bool isEmpty() const;

    /*******************************************************************
     *  node<T>* InsertHead(T i);
     *     This inserts the value at the head of the list
     *      and returns a pointer to it..
     * *****************************************************************/
    node<T>* InsertHead(T i);       //IN - value to insert

    /*******************************************************************
     *  node<T>* InsertAfter(T i,
                                 node<T>* iMarker);
     *     This inserts the value after the marker in the list
     *        and returns a pointer to it..
     * *****************************************************************/
    node<T>* InsertAfter(T i,       //IN - value to insert
                 node<T>* iMarker); //IN - insert aftert this marker

    /*******************************************************************
     *  node<T>* InsertBefore(T i,
                                  node<T>* iMarker);
     *     This inserts the value before the marker in the list
     *      and returns a pointer to it..
     * *****************************************************************/
    node<T>* InsertBefore(T i,          //IN - value to insert
                node<T>* iMarker);      //IN - insert before this marker

    /*******************************************************************
     *  node<T>* InsertSorted(T i);
     *     This inserts the value into an assumed sorted list  and
     *          returns a pointer to it.
     * *****************************************************************/
    node<T>* InsertSorted(T i);         // IN - insert i. Assume sorted list


    /*******************************************************************
     *  T Delete(node<T>* iMarker);
     *     This deletes the node at the marker from the list.
     * *****************************************************************/
    T Delete(node<T>* iMarker);         // IN - delete node pointed by iMarker


    /*******************************************************************
     *  void Print() const;
     *     This prints the contents of the list.
     * *****************************************************************/
    void Print() const;

    /*******************************************************************
     *  node<T>* Search(const T &key);
     *     This searches the list for the key and returns a pointer to it.
     * *****************************************************************/
    node<T>* Search(const T &key);      //IN - search for this value


    /*******************************************************************
     *  node<T>* Prev(node<T>* iMarker);
     *     This returns a pointer to a node previous to the marker.
     * *****************************************************************/
    node<T>* Prev(node<T>* iMarker);    //IN - find node previous to this


    /*******************************************************************
     *  T& operator[](int index);
     *     This returns an item in the list by ref at the passed index.
     * *****************************************************************/
    T& operator[](int index);           //IN - index to access

    /*******************************************************************
     *  node<T>* Begin() const;
     *     This returns a pointer to the head of the list.
     * *****************************************************************/
    node<T>* Begin() const;

    /*******************************************************************
     *  node<T>* End() const;
     *     This returns a pointer to the end of the list.
     * *****************************************************************/
    node<T>* End() const;


    /***************************************
     *  friend ostream& operator <<(ostream& outs,
                                const List<U>& l){

     * --------------------------------------------------------------------
     *  This returns an augmented output stream with the contents of the list.
     * --------------------------------------------------------------------
     *  INPUT:
     *      outs - output stream
     *      l - list to output
     * OUTPUT:
     *     outs, the augmented output stream.
     *
     * *************************************/
    template <class U>
    friend ostream& operator <<(ostream& outs,      //IN - output stream
                         const List<U>& l){         //IN - list to output
        node<U>* w = l.Begin();                     //IN - to traverse
        while (w){
            outs << w->_item <<endl;
            w = w->next;
        }
        return outs;
    }
private:
    node<T>* head;      //ATT - front of list

};

/***************************************
 *  bool List<T>::isEmpty() const

 * --------------------------------------------------------------------
 *  This checks if the list is empty.
 * --------------------------------------------------------------------
 *  INPUT:
 *      None
 * OUTPUT:
 *     true or false if list is empty
 *
 * *************************************/
template<class T>
bool List<T>::isEmpty() const{
    return (this->head == nullptr);
}

/***************************************
 *  List<T>::List(){

 * --------------------------------------------------------------------
 *  This constructor sets the head of the list to NULL
 * --------------------------------------------------------------------
 *  INPUT:
 *      None
 * OUTPUT:
 *     None
 *
 * *************************************/
template <class T>
List<T>::List(){
    head = NULL;
}

/***************************************
 *  List<T>::List(){

 * --------------------------------------------------------------------
 *  This destructor clears the list by deallocating.
 * --------------------------------------------------------------------
 *  INPUT:
 *      None
 * OUTPUT:
 *     None
 *
 * *************************************/
template<class T>
List<T>::~List(){
    _ClearList(head);
}

/***************************************
 *  List<T>::List(const List<T> &copyThis){

 * --------------------------------------------------------------------
 *  This copy constructor copies the past list to the newly created list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      copyThis - the list to copy
 * OUTPUT:
 *     None
 *
 * *************************************/
template<class T>
List<T>::List(const List<T> &copyThis){     //IN - list to copy
    this->head= _CopyList(copyThis.head);
}

/***************************************
 *  void List<T>::Print() const{
 * --------------------------------------------------------------------
 *  This function prints the items in the list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      None
 * OUTPUT:
 *     None
 *
 * *************************************/
template<class T>
void List<T>::Print() const{
    PrintList(head);
}

/***************************************
 *  node<T>* List<T>::InsertHead(T i){
 * --------------------------------------------------------------------
 *  This function is the public interface to inserting at the head of the list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      None
 * OUTPUT:
 *     None
 *
 * *************************************/
template<class T>
node<T>* List<T>::InsertHead(T i){  //IN - value to insert
    return _InsertHead(head, i);
}

/***************************************
 *  node<T>* List<T>::InsertAfter(T i, node<T>* iMarker){
 * --------------------------------------------------------------------
 *  This function is the public interface to inserting a value
 *      after a passed node in the list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      i - value to insert
 *      iMarker - the marker to insert after this point
 * OUTPUT:
 *     returns pointer to the inserted node
 *
 * *************************************/
template<class T>
node<T>* List<T>::InsertAfter(T i,      //IN - value to insert
             node<T>* iMarker){         //IN - insert after this
    if (head == NULL){
        return InsertHead(i);
    }
    return _InsertAfter(iMarker, i);
}

/***************************************
 *  node<T>* List<T>::InsertBefore(T i, node<T>* iMarker)
 * --------------------------------------------------------------------
 *  This function is the public interface to inserting a value
 *      before a passed node in the list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      i - value to insert
 *      iMarker - the marker to insert before this point
 * OUTPUT:
 *     returns pointer to the inserted node
 *
 * *************************************/
template<class T>
node<T>* List<T>::InsertBefore(T i, node<T>* iMarker){  // IN - before ptr
    if (head == NULL){
        return InsertHead(i);
    }
    return _InsertBefore(head, iMarker, i);
}

/***************************************
 *  node<T>* List<T>::InsertSorted(T i){
 * --------------------------------------------------------------------
 *  This function is the public interface to inserting a value
 *      into a sorted list.
 * --------------------------------------------------------------------
 *  INPUT:
 *      i - value to insert
 * OUTPUT:
 *     returns pointer to the inserted node
 *
 * *************************************/
template<class T>
node<T>* List<T>::InsertSorted(T i){        // IN - insert this
    return _InsertSorted(head, i, true);
}

/***************************************
 *  T List<T>::Delete(node<T>* iMarker)
 * --------------------------------------------------------------------
 *  This function is the public interface to the delete function
 * --------------------------------------------------------------------
 *  INPUT:
 *      iMarker - pointer to node that needs to be deleted
 * OUTPUT:
 *     returns the value of the deleted node
 *
 * *************************************/
template<class T>
T List<T>::Delete(node<T>* iMarker){        //IN - delete this
    return _DeleteNode(head, iMarker);
}

/***************************************
 *  node<T>* List<T>::Search(const T &key)
 * --------------------------------------------------------------------
 *  This function is the public interface to the search function.
 * --------------------------------------------------------------------
 *  INPUT:
 *      key - the object to search for
 * OUTPUT:
 *     returns pointer to the value found in the list.
 *
 * *************************************/
template<class T>
node<T>* List<T>::Search(const T &key){     //IN - search for this
    return SearchList(head, key);
}

/***************************************
 *  node<T>* List<T>::Prev(node<T>* iMarker)
 * --------------------------------------------------------------------
 *  This function returns a pointer to the node previous to the marker.
 * --------------------------------------------------------------------
 *  INPUT:
 *      iMarker - pointer to find previous of
 * OUTPUT:
 *     returns pointer to the node in front of the passed pointer
 *
 * *************************************/
template<class T>
node<T>* List<T>::Prev(node<T>* iMarker){   //IN - ptr prev to this
    return _PreviousNode(head, iMarker);
}

/***************************************
 *  T& List<T>::operator[](int index){
 * --------------------------------------------------------------------
 *  This function returns a reference to the value at the pointer.
 * --------------------------------------------------------------------
 *  INPUT:
 *      index - index of value to return reference of
 * OUTPUT:
 *     returns reference to element of list at location
 *
 * *************************************/
template<class T>
T& List<T>::operator[](int index){  //IN - position of element
    return At(head, index);
}

/***************************************
 *  node<T>* List<T>::Begin() const
 * --------------------------------------------------------------------
 *  This function returns a pointer to the head of the list
 * --------------------------------------------------------------------
 *  INPUT:
 *      None
 * OUTPUT:
 *     pointer to head of the list.
 *
 * *************************************/
template<class T>
node<T>* List<T>::Begin() const{
    return head;
}

/***************************************
 *  node<T>* List<T>::End() const
 * --------------------------------------------------------------------
 *  This function returns a pointer to the end of the list
 * --------------------------------------------------------------------
 *  INPUT:
 *      None
 * OUTPUT:
 *     pointer to end of the list.
 *
 * *************************************/
template<class T>
node<T>* List<T>::End() const{
    return LastNode(head);
}


#endif // LIST_H
