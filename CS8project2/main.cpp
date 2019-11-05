#include "mainwindow.h"
#include "adjlist.h"
#include "souvenir.h"
#include <QApplication>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{

    ListofStadiumList list;
    list.addStadium(stadium("a","b","c","d","e","f"));

//    stadium* temp = list.getStadium("a");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


}
