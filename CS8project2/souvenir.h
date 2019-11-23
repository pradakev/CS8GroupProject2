#ifndef SOUVENIR_H
#define SOUVENIR_H
#include <iostream>
#include <cassert>
using namespace std;

struct souvenir{

    souvenir(){}
    souvenir(string name, string price){
        _name = name;
        _price = price;
    }
    //GETTERS
    string getName(){
        return _name;
    }

    string getPrice(){
        return _price;
    }

    //SETTERS
    void setName(string name){
        _name = name;
    }

    void setPrice(string price){
        _price = price;
    }

private:
    string _name;
    string _price;
};


class souvenirs
{
public:
    souvenirs();
    ~souvenirs();
    souvenirs(const souvenirs& other);
    souvenirs& operator = (const souvenirs& other);
    souvenir& operator [](int index);

    //GETTERS
    int getSize();

    //FUNCTIONS
    void addSouvenir(souvenir);
    void removeSouvenir(int index);

private:
    souvenir* _s;
    int _size;
};

#endif // SOUVENIR_H
