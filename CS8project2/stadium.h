#ifndef STADIUM_H
#define STADIUM_H
#include <iostream>
#include <sstream>

using namespace std;

class stadium
{
public:
    stadium();
    stadium(string, string, string, string, string, string, string);

    bool operator == (const stadium& other);

    //GETTERS
    string getStadiumName();
    string getTeamName();
    string getAddress();
    string getPhone();
    string getOpenDate();
    string getCapacity();
    string getType();
    string getAllInfo();

    //SETTERS
    void setName(string);
    void setTeamName(string);
    void setAddress(string);
    void setphone(string);
    void setOpenDate(string);
    void setCapacity(string);
    void setType(string);

    //test function
    void print(){
        cout << _sName <<endl << _teamName << endl<< _address <<endl
             << _phone << endl<< _openDate << endl<<_capacity
             <<endl<< _type <<endl;
    }

private:
    string _sName;
    string _teamName;
    string _address;
    string _phone;
    string _openDate;
    string _capacity;
    string _type;
};

#endif // STADIUM_H
