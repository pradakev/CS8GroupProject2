#ifndef SOUVENIR_H
#define SOUVENIR_H
#include <iostream>
using namespace std;

struct souvenir{

    souvenir(){};
    souvenir(string name, double price){
        _name = name;
        _price = price;
    }
    //GETTERS
    string getName(){
        return _name;
    }

    double getPrice(){
        return _price;
    }

    //SETTERS
    void setName(string name){
        _name = name;
    }

    void setPrice(double price){
        _price = price;
    }

private:
    string _name;
    double _price;
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
