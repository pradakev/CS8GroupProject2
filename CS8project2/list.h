#ifndef LIST_H
#define LIST_H
#include "linked_list_functions.h"
template <class T>
class List
{
public:
    List();

    ~List();
    List(const List<T> &copyThis);
    List& operator =(const List& RHS){
        _ClearList(head);
        head = _CopyList(RHS.head);
        return *this;
    }

    node<T>* InsertHead(T i);           //inset i at the head of list

    node<T>* InsertAfter(T i,           //insert i after iMarker
                                 node<T>* iMarker);

    node<T>* InsertBefore(T i,          //insert i before iMarker
                                  node<T>* iMarker);

    node<T>* InsertSorted(T i);         //insert i. Assume sorted list



    T Delete(node<T>* iMarker);         //delete node pointed to by iMarker


    void Print() const;                                 //print the list

    node<T>* Search(const T &key);      //return pointer to node containing
                                                        //  key. NULL if not there

    node<T>* Prev(node<T>* iMarker);    //get the previous node to iMarker


    T& operator[](int index);                   //return the item at index

    node<T>* Begin() const;                     //return the head of the list

    node<T>* End() const;                       //return the tail of the list
                                                        //  if you ever have to use this
                                                        //  function, you need to redesign
                                                        //  your program.
    template <class U>
    friend ostream& operator <<(ostream& outs,          //insertion operator for list
                                const List<U>& l);
private:
    node<T>* head;

};
template <class T>
List<T>::List(){
    head = NULL;
}

template<class T>
List<T>::~List(){
    _ClearList(head);
}

template<class T>
List<T>::List(const List<T> &copyThis){
    head = _CopyList(copyThis.head);
}

template <class U>
ostream& operator <<(ostream& outs, const List<U>& l){
    node<U>* w = l.head;
    while (w != NULL){
        outs << *w;
        w = w->next;
    }
    return outs;
}

template<class T>
void List<T>::Print() const{
    PrintList(head);
}

template<class T>
node<T>* List<T>::InsertHead(T i){
    return _InsertHead(head, i);
}

template<class T>
node<T>* List<T>::InsertAfter(T i, node<T>* iMarker){
    if (head == NULL){
        return InsertHead(i);
    }
    return _InsertAfter(iMarker, i);
}

template<class T>
node<T>* List<T>::InsertBefore(T i, node<T>* iMarker){
    if (head == NULL){
        return InsertHead(i);
    }
    return _InsertBefore(head, iMarker, i);
}

template<class T>
node<T>* List<T>::InsertSorted(T i){
    return _InsertSorted(head, i, true);
}

template<class T>
T List<T>::Delete(node<T>* iMarker){
    return _DeleteNode(head, iMarker);
}

template<class T>
node<T>* List<T>::Search(const T &key){
    return SearchList(head, key);
}

template<class T>
node<T>* List<T>::Prev(node<T>* iMarker){
    return _PreviousNode(head, iMarker);
}

template<class T>
T& List<T>::operator[](int index){
    return At(head, index);
}

template<class T>
node<T>* List<T>::Begin() const{
    return head;
}

template<class T>
node<T>* List<T>::End() const{
    return LastNode(head);
}

#endif // LIST_H
