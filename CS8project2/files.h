#ifndef FILES_H
#define FILES_H
#include <fstream>
#include <sstream>
#include "graph.h"
#include "souvenir.h"

void readStadiums(graph &g, string fileName){
    ifstream infile;
    infile.open(fileName);

    string line;
    stadium toAdd;

    if (!infile){
        cout << "file not found. " <<endl;
    }

    while (infile){
        getline(infile, line);
        toAdd.setName(line);

        getline(infile, line);
        toAdd.setTeamName(line);

        getline(infile, line);
        toAdd.setAddress(line);

        getline(infile, line);
        toAdd.setphone(line);

        getline(infile, line);
        toAdd.setOpenDate(line);

        getline(infile, line);
        toAdd.setCapacity(line);

        getline(infile, line);
        toAdd.setType(line);

        getline(infile, line);
        toAdd.setFieldSurface(line);

        //x and y coordinates of pixels
        getline(infile, line);
        toAdd.setXCoor(stoi(line));
        getline(infile, line);
        toAdd.setYCoor(stoi(line));

        getline(infile, line);

        g.addStadium(toAdd);
    }
    infile.close();
}

void readEdges(graph &g, string fileName){
    ifstream infile;
    infile.open(fileName);

    string line;
    string s1;
    string s2;
    int distance;

    if (!infile){
        cout << "file not found. " <<endl;
    }
    while (infile){
        getline(infile, line);
        s1 = line.substr(0, line.find(","));
        line = line.substr(line.find(",")+2);
        s2 = line.substr(0, line.find(","));
        line = line.substr(line.find(",")+1);
        distance = stoi(line);
        g.addEdge(s1,s2,distance);
        g.addEdge(s2,s1,distance);
    }
    infile.close();
}

void readSouvenirs(souvenirs& s, string fileName){
    ifstream infile;
    infile.open(fileName);

    string line;
    souvenir toAdd;

    if (!infile){
        cout << "file not found. " <<endl;
    }

    while (!infile.eof()){
        getline(infile, line);
        toAdd.setName(line.substr(0, line.find(",")));
        line = line.substr(line.find(",")+3);
        toAdd.setPrice(line);

        s.addSouvenir(toAdd);
    }
}

void saveStadiums(graph &g, string fileName){

    cout << "HI " <<endl;
    node<stadium>* w = g.getStadiumList().Begin();

    ofstream outfile;
    outfile.open(fileName);

    stringstream ss;

    string tostr;
    do{
        ss << w->_item.getStadiumName() <<endl;
        ss << w->_item.getTeamName() <<endl;
        ss << w->_item.getAddress() <<endl;
        ss << w->_item.getPhone() <<endl;
        ss << w->_item.getOpenDate() <<endl;
        ss << w->_item.getCapacity() <<endl;
        ss << w->_item.getType() <<endl;
        ss << w->_item.getFieldSurface();

        tostr = ss.str();
        cout << tostr <<endl;

        outfile << tostr;
        ss.clear();
        if (w->next != nullptr){
            outfile <<endl;
        }

        w = w->next;
    }while(w->next);
    outfile.close();

}

void saveSouvenirs(souvenirs& s, string fileName){

    ofstream outfile;
    outfile.open(fileName);

    for (int i = 0; i < s.getSize(); i++){
        if (i == s.getSize()-1){
            outfile << s[i].getName() << ", $" << s[i].getPrice();
        }
        else{
            outfile << s[i].getName() << ", $" << s[i].getPrice() <<endl;
        }
    }

    outfile.close();
}
#endif // FILES_H
