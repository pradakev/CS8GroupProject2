/***************************************
 * AUTHOR                : Justin Kuhn, Anna Ma, Kevin Prada
 * Project 2             : I Love Baseball
 * CLASS                 : CS8
 * SECTION               : MW 9:45-11:10AM TTH 9:45-11:50AM
 * Due Date              : 12/5/19
 * *************************************/

#include "stadium.h"

/***************************************
 * stadium::stadium(){}
 * --------------------------------------------------------------------
 *  This is the default constructor
 *
 * --------------------------------------------------------------------
 *  INPUT:
 *     None
 * OUTPUT:
 *      None
 * *************************************/
stadium::stadium(){}
/***************************************
 * stadium::stadium(string name, string teamName, string address,
                 string phone, string openDate, string capacity, string type
                 ,string surface){
 * --------------------------------------------------------------------
 *  This constructor initializes all values of a stadium object.
 *
 * --------------------------------------------------------------------
 *  INPUT:
 *      name -  stadium name
 *      teamName -  name of team at stadium
 *      address -   address of stadium
 *      phone -     phone number of stadium
 *      openDate -  open date of stadium
 *      capacity -  capacity of stadium
 *      type -      league of stadium
 *      surface -   field surface type
 * OUTPUT:
 *      None
 * *************************************/
stadium::stadium(string name,       // IN - std name
                 string teamName,   // IN - team at std
                 string address,    // IN - std addres
                 string phone,      // IN - assoc. phone
                 string openDate,   // IN - day std opened
                 string capacity,   // IN - cap of std
                 string type        // IN - std leage
                 ,string surface){  // IN - std surface
    _sName = name;
    _teamName = teamName;
    _address = address;
    _phone = phone;
    _openDate = openDate;
    _capacity = capacity;
    _type = type;
    _surface = surface;
}

/***************************************
 * bool stadium::operator == (const stadium& other){
 * -----------------------------
 *  This chekcs if the other stadium is equal to the calling stadium.
 *
 * --------------------------------------------------------------------
 *  INPUT:
 *      other - the stadium to check
 * OUTPUT:
 *      None
 * *************************************/
bool stadium::operator == (const stadium& other){   // IN - to copy
    return this->_sName == other._sName;
}

//GETTERS
/***************************************
 * string stadium::getAllInfo(){
 * -----------------------------
 *  This returns a string of all the relevent information for a stadium.
 *
 * --------------------------------------------------------------------
 *  INPUT:
 *      other - the stadium to check
 * OUTPUT:
 *      None
 * *************************************/
string stadium::getAllInfo(){
    stringstream ss;
    ss << getStadiumName() <<endl;
    ss << getTeamName()<<endl;
    ss << getAddress() <<endl;
    ss << "Phone: " << getPhone() <<endl;
    ss << "Founded: "<<getOpenDate() <<endl;
    ss << "Capacity: " << getCapacity() <<endl;
    ss << "League: " << getType() <<endl;
    ss << "Field surface: " << getFieldSurface() <<endl;

    return string(ss.str());
}



