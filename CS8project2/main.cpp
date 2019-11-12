#include "mainwindow.h"
#include "files.h"
#include <QApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{

    graph t;

    string str = "stadiumInfo.txt";
    readStadiums(t, str);

    stadium temp = t.getStadiumInfo("Comerica Park");

//    temp.print();
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();

}
