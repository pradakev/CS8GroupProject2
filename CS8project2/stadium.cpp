#include "stadium.h"

stadium::stadium(){}
stadium::stadium(string name, string teamName, string address,
                 string phone, string openDate, string capacity, string type){
    _sName = name;
    _teamName = teamName;
    _address = address;
    _phone = phone;
    _openDate = openDate;
    _capacity = capacity;
    _type = type;
}

bool stadium::operator == (const stadium& other){
    return this->_sName == other._sName;
}

//GETTERS
string stadium::getStadiumName(){
    return _sName;
}

string stadium::getTeamName(){
    return _teamName;
}

string stadium::getAddress(){
    return _address;
}

string stadium::getPhone(){
    return _phone;
}

string stadium::getOpenDate(){
    return _openDate;
}

string stadium::getCapacity(){
    return _capacity;
}

string stadium::getType(){
    return _type;
}

string stadium::getAllInfo(){
    stringstream ss;
    ss << getStadiumName() <<endl;
    ss << getTeamName()<<endl;
    ss << getAddress() <<endl;
    ss << "Phone: " << getPhone() <<endl;
    ss << "founded: "<<getOpenDate() <<endl;
    ss << "capacity: " << getCapacity() <<endl;
    ss << "League: " << getType() <<endl;

    return string(ss.str());
}

//SETTERS
void stadium::setName(string name){
    _sName = name;
}

void stadium::setTeamName(string tname){
    _teamName = tname;
}

void stadium::setAddress(string address){
    _address = address;
}

void stadium::setphone(string phone){
    _phone = phone;
}

void stadium::setOpenDate(string openDate){
    _openDate = openDate;
}

void stadium::setCapacity(string capacity){
    _capacity = capacity;
}

void stadium::setType(string type){
    _type = type;
}
