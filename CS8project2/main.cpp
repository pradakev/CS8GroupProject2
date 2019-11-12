#include "mainwindow.h"
#include "files.h"
#include <QApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{

    graph t;
    readStadiums(t, "stadiumInfo.txt");
    readEdges(t, "stadiumDistances.txt");


//    temp.print();
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();

}
