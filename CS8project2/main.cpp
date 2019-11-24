#include "mainwindow.h"
#include <QApplication>
#include <iostream>
//#include "files.h"
using namespace std;
int main(int argc, char *argv[])
{

//    graph g;
//    readStadiums(g, "stadiumInfo.txt");

//    List<stadium> temp = g.getStadiumWithGrassField();
//    node<stadium> * w = temp.Begin();
//    while (w){
//        w->_item.print();
//        w = w->next;
//    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
