#include "mainwindow.h"
#include "graph.h"
#include "souvenir.h"
#include <QApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{

    // sample usage
    graph t;
    stadium src1 = stadium("stadium1","b","c","d","e","f","g");
    stadium src2 = stadium("stadium2","b","c","d","e","f","g");
    stadium src3 = stadium("stadium3","b","c","d","e","f","g");


    t.addStadium(src1);
    t.addStadium(src2);
    t.addStadium(src3);
    t.addEdge("stadium1", "stadium2", 30);
    t.addEdge("stadium1", "stadium3", 20);
    t.addEdge("stadium2", "stadium1", 50);

    cout << "distance bewteen 1 to 2 stadiums: " << t.getedge("stadium1", "stadium2")<<endl;

    cout << "distance bewteen 1 to 3 stadiums: " << t.getedge("stadium1", "stadium3") <<endl;

    cout << "stad2 to stad1 : " << t.getedge("stadium2", "stadium1") <<endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
