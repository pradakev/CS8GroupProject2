/***************************************
 * AUTHOR                : Justin Kuhn, Anna Ma, Kevin Prada
 * Project 2             : I Love Baseball
 * CLASS                 : CS8
 * SECTION               : MW 9:45-11:10AM TTH 9:45-11:50AM
 * Due Date              : 12/5/19
 * *************************************/

#include "souvenir.h"

/***************************************
 * souvenirs::souvenirs(){
 * --------------------------------------------------------------------
 *  This constructor creates a new array of souvenirs with a size of 0.
 *
 * --------------------------------------------------------------------
 *  INPUT:
 *     None
 * OUTPUT:
 *      None
 * *************************************/
souvenirs::souvenirs(){
    _s = new souvenir[1];
    _size = 0;
}

/***************************************
 * souvenirs::~souvenirs(){
 * --------------------------------------------------------------------
 *  This destructor deallocates the array of souvenirs
 *
 * --------------------------------------------------------------------
 *  INPUT:
 *     None
 * OUTPUT:
 *      None
 * *************************************/
souvenirs::~souvenirs(){
    delete [] _s;
}

/***************************************
 * souvenirs::souvenirs(const souvenirs& other){
 * --------------------------------------------------------------------
 *  This copy constructor copies the other list to the created list.
 *
 * --------------------------------------------------------------------
 *  INPUT:
 *     other - souvenirs to copy
 * OUTPUT:
 *      None
 * *************************************/
souvenirs::souvenirs(const souvenirs& other){
    *this = other;
}

/***************************************
 * souvenirs& souvenirs::operator = (const souvenirs& other){
 * --------------------------------------------------------------------
 *  This assignment operator copies the other array to the current
 *    souvenir array.
 *
 * --------------------------------------------------------------------
 *  INPUT:
 *     other - souvenirs to copy
 * OUTPUT:
 *      reference to the calling object
 * *************************************/
souvenirs& souvenirs::operator = (const souvenirs& other){
    this->_s = new souvenir[other._size];
    this->_size = other._size;
    for (int i = 0; i < this->_size; i++){
        this->_s[i] = other._s[i];
    }
    return *this;
}
/***************************************
 * souvenir& souvenirs::operator [](int index){
 * --------------------------------------------------------------------
 *  This overloads the brackets operator to acces a specific index
 *      of the souvenirs array.
 *
 * --------------------------------------------------------------------
 *  INPUT:
 *     index - position to access
 * OUTPUT:
 *     returns a reference to the object at the position
 * *************************************/
souvenir& souvenirs::operator [](int index){
    return _s[index];
}

//GETTERS
/***************************************
 * int souvenirs::getSize(){
 * --------------------------------------------------------------------
 *  This returns the size of the souvenirs array
 *
 * --------------------------------------------------------------------
 *  INPUT:
 *     None
 * OUTPUT:
 *     None
 * *************************************/
int souvenirs::getSize(){
    return _size;
}

//FUNCTIONS
/***************************************
 * void souvenirs::addSouvenir(souvenir addMe){
 * --------------------------------------------------------------------
 *  This adds the passed souvenir to the array
 *
 * --------------------------------------------------------------------
 *  INPUT:
 *     addMe - souvenir to add
 * OUTPUT:
 *     None
 * *************************************/
void souvenirs::addSouvenir(souvenir addMe){
    souvenirs temp(*this);

    this->_s = new souvenir[this->_size+1];
    for (int i = 0; i < this->_size; i++){
        this->_s[i] = temp._s[i];
    }
    this->_s[_size] = addMe;
    this->_size++;
}

/***************************************
 * void souvenirs::removeSouvenir(int index){
 * --------------------------------------------------------------------
 *  This removes the souvenir at the specified index from the souvenirs list.
 *
 * --------------------------------------------------------------------
 *  INPUT:
 *     index - remove element at this position
 * OUTPUT:
 *     None
 * *************************************/
void souvenirs::removeSouvenir(int index){
    assert(this->_size >=1);

    souvenirs temp(*this);

    this->_s = new souvenir[this->_size-1];
    for (int i = 0; i < this->_size; i++){
        if (i != index){
            this->_s[i] = temp._s[i];
        }
    }
    this->_size--;
}

int souvenirs::getItemCount(string itemName){
    int count = 0;
    for (int i = 0; i < this->_size; i++){
        if (_s[i].getName() == itemName){
            count++;
        }
    }
    return count;
}

bool souvenirs::operator == (const souvenirs& other){

    if (this->_size != other._size){
        return false;
    }
    for (int i = 0; i < this->_size; i++){
        if (this->_s[i].getName() != other._s[i].getName()){
            return false;
        }
    }
    return true;
}
