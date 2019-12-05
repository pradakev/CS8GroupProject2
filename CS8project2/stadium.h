/***************************************
 * AUTHOR                : Justin Kuhn, Anna Ma, Kevin Prada
 * Project 2             : I Love Baseball
 * CLASS                 : CS8
 * SECTION               : MW 9:45-11:10AM TTH 9:45-11:50AM
 * Due Date              : 12/5/19
 * *************************************/

#ifndef STADIUM_H
#define STADIUM_H
#include <iostream>
#include <sstream>

using namespace std;

/*******************************************************************
 *  stadium class
 *      This class represnts all the information associatied with a stadium.
 *          It mananges stadiumName, teamName, Address, Phone, Type, and
 *          field surface.
 * *****************************************************************/
class stadium
{
public:
    /*******************************************************************
     *  stadium();
     *     This uses the default constructor.
     * *****************************************************************/
    stadium();
    /*******************************************************************
     *  stadium(string, string, string, string, string, string, string, string);
     *     This constructor initializes all of the attributes of a stadium.
     * *****************************************************************/
    stadium(string, // IN -  stadium name to set
            string, // IN -  team name to set
            string, // IN -  address to set
            string, // IN -  phone to set
            string, // IN -  open date to set
            string, // IN -  capacity to set
            string, // IN -  league to set
            string);// IN -  field surface to set

    /*******************************************************************
     *  bool operator == (const stadium& other);
     *     This checks of one stadium has the same name as another stadium
     * *****************************************************************/
    bool operator == (const stadium& other); // IN - stadium to copy


    //GETTERS
    // These functions simply return the values for the respective variables
    string getStadiumName(){
        return _sName;
    }

    string getTeamName(){
        return _teamName;
    }

    string getAddress(){
        return _address;
    }

    string getPhone(){
        return _phone;
    }

    string getOpenDate(){
        return _openDate;
    }

    string getCapacity(){
        return _capacity;
    }

    string getType(){
        return _type;
    }
    string getFieldSurface(){
        return _surface;
    }


    int getXCoor()
    {
        return xPixel;
    }

    int getYCoor()
    {
        return yPixel;
    }
    /*******************************************************************
     *  string getAllInfo();
     *     This returns all of the info for a stadium
     * *****************************************************************/
    string getAllInfo();




    //SETTERS

    // These functions simply set the values for the respective variables
    void setName(string name){          // IN - stadium name to set
        _sName = name;
    }

    void setTeamName(string tname){     // IN - team name to set
        _teamName = tname;
    }

    void setAddress(string address){    // IN -  address to set
        _address = address;
    }

    void setphone(string phone){        // IN -  phone to set
        _phone = phone;
    }

    void setOpenDate(string openDate){  // IN -  openDate to set
        _openDate = openDate;
    }

    void setCapacity(string capacity){  // IN -  capacity to set
        _capacity = capacity;
    }

    void setType(string type){          // IN -  type to set
        _type = type;
    }

    void setFieldSurface(string surface){   // IN -  surface to set
        _surface = surface;
    }

    void setXCoor(int xpos)             // IN -  x pos to set(for map)
    {
        xPixel = xpos;
    }

    void setYCoor(int ypos)             // IN -  y pos to set(for map)
    {
        yPixel = ypos;
    }


    /*******************************************************************
     *  friend ostream& operator << (ostream& outs, const stadium& s){
     *     This overloading the insertion operator for stadiums.
     * *****************************************************************/
    friend ostream& operator << (ostream& outs,         // OUT -  output stream
                                 const stadium& s){     // IN -  stadium to out
        outs << s._sName;
        return outs;
    }

private:
    string _sName;      //ATT - stadium name
    string _teamName;   //ATT - team name
    string _address;    //ATT - stadium address
    string _phone;      //ATT - stadium phone
    string _openDate;   //ATT - stadium open date
    string _capacity;   //ATT - stadium capacity
    string _type;       //ATT - stadium league type
    string _surface;    //ATT - stadium field surface

    //Pixel Coordinates
    int xPixel;         //ATT - x coor of stadium on map
    int yPixel;         //ATT - y coor of stadium on map
};

#endif // STADIUM_H
