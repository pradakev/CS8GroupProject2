#ifndef SOUVENIR_H
#define SOUVENIR_H
#include <iostream>
using namespace std;

struct souvenir{
    //GETTERS
    string getName();
    double getPrice();

    //SETTERS
    void setName(string);
    void setPrice(double);

    //VARIABLES
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

private:
    souvenir* _s;
    int _size;
};

#endif // SOUVENIR_H
