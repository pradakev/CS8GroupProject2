#ifndef FILES_H
#define FILES_H
#include <fstream>
#include "graph.h"
#include "souvenir.h"

void readStadiums(graph &g, string fileName){
    ifstream infile;
    infile.open(fileName);

    string line;
    stadium toAdd;

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

    while (!infile.eof()){
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

    while (!infile.eof()){
        getline(infile, line);
        toAdd.setName(line.substr(0, line.find(",")));
        line = line.substr(line.find(",")+3);
        toAdd.setPrice(stod(line));

        s.addSouvenir(toAdd);
    }
}

void saveStadiums(graph &g, string fileName);

void saveEdges(graph& g, string fileName);

void saveSouvenirs(souvenirs& s, string fileName);
#endif // FILES_H
