#ifndef FILES_H
#define FILES_H
#include <fstream>
#include "graph.h"

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

        g.addStadium(toAdd);
    }
    infile.close();
}

void readEdges(graph &g, string fileName){

}

void saveStadiums(graph &g, string fileName){

}

void saveEdges(graph& g, string fileName){

}
#endif // FILES_H
