#ifndef FILES_H
#define FILES_H
#include <fstream>
#include "graph.h"
void readStadiums(graph &g, string fileName)
{

    stadium *temp;            // CALC - temp member for reading info

    string name, team, address1,address2, phone, open, cap, type = "";

    ifstream stadiums;        // IN - Input stream object for files

    temp = new stadium;

    stadiums.open(fileName);


    if ( stadiums.fail() )
    {
        cout << endl << "Fail!" << endl;         // Output error message
        exit(1);
    }

    while(!stadiums.eof() )
    {

        getline(stadiums, name, '\n');
        getline(stadiums, team, '\n');
        getline(stadiums, address1, '\n');
        getline(stadiums, address2, '\n');
        getline(stadiums, phone, '\n');
        getline(stadiums, open, '\n');
        getline(stadiums, cap, '\n');
        getline(stadiums, type, '\n');

        temp = new stadium(name,team,address1+address2, phone,open, cap, type);

        g.addStadium(*temp);

    }

}

void readEdges(graph &g, string fileName){

}

void saveStadiums(graph &g, string fileName){

}

void saveEdges(graph& g, string fileName){

}
#endif // FILES_H
