/***************************************
 * AUTHOR                : Justin Kuhn, Anna Ma, Kevin Prada
 * Project 2             : I Love Baseball
 * CLASS                 : CS8
 * SECTION               : MW 9:45-11:10AM TTH 9:45-11:50AM
 * Due Date              : 12/5/19
 * *************************************/

#ifndef SOUVENIR_H
#define SOUVENIR_H
#include <iostream>
#include <cassert>
using namespace std;

/*******************************************************************
 *  souvenir struct
 *      represents a single souvenir with a price and name
 * *****************************************************************/
struct souvenir{

    /*******************************************************************
     *  souvenir()
     *     This uses the default constructor.
     * *****************************************************************/
    souvenir(){}
    /*******************************************************************
     *  souvenir(string name, string price)
     *     This sets the name and price of a new souvenir
     * *****************************************************************/
    souvenir(string name,       // IN -  name of souvenir
             string price){     // IN - price of souvenir
        _name = name;
        _price = price;
    }
    //GETTERS
    /*******************************************************************
     *  string getName()
     *     Return the name of the souvenir
     * *****************************************************************/
    string getName(){
        return _name;
    }

    /*******************************************************************
     *  string getPrice()
     *     Return the price of the souvenir
     * *****************************************************************/
    string getPrice(){
        return _price;
    }

    //SETTERS
    /*******************************************************************
     *  void setName(string name)
     *     Set the name of the souvenir
     * *****************************************************************/
    void setName(string name){  // IN -  name of souvenir
        _name = name;
    }

    /*******************************************************************
     *   void setPrice(string price){
     *     Set the price of the souvenir
     * *****************************************************************/
    void setPrice(string price){    // IN -  price of souvenir
        _price = price;
    }

private:
    string _name;       //ATT- name of souvenir
    string _price;      //ATT- price of souvenir
};


/*******************************************************************
 *  souvenirs class
 *      represents an array of souvenir objects
 * *****************************************************************/
class souvenirs
{
public:
    /*******************************************************************
     *  souvenir()
     *     This initializes an empty array of souvenirs
     * *****************************************************************/
    souvenirs();
    /*******************************************************************
     *  souvenir()
     *     This delete an array of souvenirs
     * *****************************************************************/
    ~souvenirs();
    /*******************************************************************
     *  souvenirs(const souvenirs& other);
     *     This copies the passed souvenirs to the new object
     * *****************************************************************/
    souvenirs(const souvenirs& other); // IN -  souvenir arr to copy
    /*******************************************************************
     *  souvenirs& operator = (const souvenirs& other);
     *     This returns a copy of the right hand souvenir
     * *****************************************************************/
    souvenirs& operator = (const souvenirs& other); //IN -  souvenir arr to copy
    /*******************************************************************
     *  souvenir& operator [](int index);
     *     This returns a souvernir at the specified index
     * *****************************************************************/
    souvenir& operator [](int index);               // IN -  index to access

    //GETTERS
    /*******************************************************************
     *  int getSize();
     *     This returns the size of the souvenir array
     * *****************************************************************/
    int getSize();

    //FUNCTIONS
    /*******************************************************************
     *   void addSouvenir(souvenir);
     *     This adds a souvenir to the array
     * *****************************************************************/
    void addSouvenir(souvenir);     // IN -  souvenir to add to arr
    /*******************************************************************
     *  void removeSouvenir(int index);
     *     This removes a souvenir from the list at the index
     * *****************************************************************/
    void removeSouvenir(int index); // IN -  index of souv to rem

private:
    souvenir* _s;   //ATT - souvenir array
    int _size;      //ATT - number of souvenirs
};

#endif // SOUVENIR_H
