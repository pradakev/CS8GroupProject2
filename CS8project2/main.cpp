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
    stadium src3 = stadium("stadium2","b","c","d","e","f","g");
    t.addStadium(src1);
    t.addStadium(src3);
    t.addEdge(src1, src3, 30);

    stadium temp = t.getStadium("stadium1");
    cout << "stadiumname: " << temp.getStadiumName() <<endl;

    cout << "distance bewteen two stadiums: " << t.getedge("stadium1", "stadium2")<<endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
