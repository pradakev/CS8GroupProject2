/***************************************
 * AUTHOR                : Justin Kuhn, Anna Ma, Kevin Prada
 * Project 2             : I Love Baseball
 * CLASS                 : CS8
 * SECTION               : MW 9:45-11:10AM TTH 9:45-11:50AM
 * Due Date              : 12/5/19
 * *************************************/
#ifndef FILES_H
#define FILES_H
#include <fstream>
#include <sstream>
#include "graph.h"
#include "souvenir.h"

/***************************************
 *  void readStadiums(graph &g, string fileName){
 *
 * --------------------------------------------------------------------
 *  This function read the stadium from the input file
 * --------------------------------------------------------------------
 *  INPUT:
 *      g - graph object
 *      fileName - name of stadium file
 * OUTPUT:
 *      None
 * *************************************/
void readStadiums(graph &g,             // IN - graph object
                  string fileName){     // IN - name of stadium file
    ifstream infile;        // IN -- input strem
    infile.open(fileName);

    string line;            // IN - each line
    stadium toAdd;          // IN - stadium being aded

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

/***************************************
 *  void readEdges(graph &g, string fileName){
 *
 * --------------------------------------------------------------------
 *  This function reads the edges connecting all the stadiums from a file.
 * --------------------------------------------------------------------
 *  INPUT:
 *      g - graph object
 *      fileName - name of stadium file
 * OUTPUT:
 *      None
 * *************************************/
void readEdges(graph &g,                        // IN - graph object
               string fileName){                // IN - name of stadium file
    ifstream infile;        // IN - name of file
    infile.open(fileName);

    string line;            // IN - each read line
    string s1;              // IN - temp subtring
    string s2;              // IN - temp substring
    int distance;           // IN - distance of edge

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

/***************************************
 *  void readSouvenirs(souvenirs& s, string fileName){
 *
 * --------------------------------------------------------------------
 *  This function reads all the sounvenir objects from a file and places them
 *  in a passed object.
 * --------------------------------------------------------------------
 *  INPUT:
 *      s - souvenir object
 *      fileName - name of file
 * OUTPUT:
 *      None
 * *************************************/
void readSouvenirs(souvenirs& s,            // IN & OUT - souvenir object
                   string fileName){        // IN - name of file
    ifstream infile;            // IN - input stream
    infile.open(fileName);

    string line;                // IN - line to read
    souvenir toAdd;             // IN - souvenir being added

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
/***************************************
 *  void saveStadiums(graph &g, string fileName){
 *
 * --------------------------------------------------------------------
 *  This function saves the current list of all stadiums
 * --------------------------------------------------------------------
 *  INPUT:
 *      g - graph object containing stadium list
 *      fileName - name of file
 * OUTPUT:
 *      None
 * *************************************/
void saveStadiums(graph &g,         // IN - graph object containing stadium list
                  string fileName){ // IN - name of output file

    List<stadium> list = g.getStadumList();     // IN - list of stadiums
    node<stadium>* w = list.Begin();            // IN - pointer to beginning

    ofstream outfile;                           // OUT - output stram
    outfile.open(fileName);

    stringstream ss;                            // OUT - stream of strings

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

/***************************************
 *  void saveSouvenirs(souvenirs& s, string fileName){
 *
 * --------------------------------------------------------------------
 *  This function saves the current list of souvenirs.
 * --------------------------------------------------------------------
 *  INPUT:
 *      s - the souvenirs object with souv's to be saved
 *      fileName - name of file
 * OUTPUT:
 *      None
 * *************************************/
void saveSouvenirs(souvenirs& s,        // IN - the souvenirs object to read
                   string fileName){    // IN - name of file

    ofstream outfile;                   // OUT - output stream
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
