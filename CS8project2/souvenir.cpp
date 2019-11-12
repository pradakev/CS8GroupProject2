#include "souvenir.h"

souvenirs::souvenirs(){
    _s = new souvenir[1];
    _size = 0;
}

souvenirs::~souvenirs(){
    delete [] _s;
}

souvenirs::souvenirs(const souvenirs& other){
    *this = other;
}

souvenirs& souvenirs::operator = (const souvenirs& other){
    this->_s = new souvenir[other._size];
    this->_size = other._size;
    for (int i = 0; i < this->_size; i++){
        this->_s[i] = other._s[i];
    }
    return *this;
}

souvenir& souvenirs::operator [](int index){
    return _s[index];
}

//GETTERS
int souvenirs::getSize(){
    return _size;
}

//FUNCTIONS
void souvenirs::addSouvenir(souvenir addMe){
    souvenirs temp(*this);

    this->_s = new souvenir[this->_size+1];
    for (int i = 0; i < this->_size; i++){
        this->_s[i] = temp._s[i];
    }
    this->_s[_size] = addMe;
    this->_size++;
}

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


