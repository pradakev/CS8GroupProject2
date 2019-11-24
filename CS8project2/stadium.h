#ifndef STADIUM_H
#define STADIUM_H
#include <iostream>
#include <sstream>

using namespace std;

class stadium
{
public:
    stadium();
    stadium(string, string, string, string, string, string, string, string);

    bool operator == (const stadium& other);

    //GETTERS
    string getStadiumName();
    string getTeamName();
    string getAddress();
    string getPhone();
    string getOpenDate();
    string getCapacity();
    string getType();
    string getFieldSurface();
    string getAllInfo();

    //SETTERS
    void setName(string);
    void setTeamName(string);
    void setAddress(string);
    void setphone(string);
    void setOpenDate(string);
    void setCapacity(string);
    void setType(string);
    void setFieldSurface(string);

    //test function
    void print(){
        cout << _surface <<endl;
    }

private:
    string _sName;
    string _teamName;
    string _address;
    string _phone;
    string _openDate;
    string _capacity;
    string _type;
    string _surface;
};

#endif // STADIUM_H
