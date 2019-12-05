/***************************************
 * AUTHOR                : Justin Kuhn, Anna Ma, Kevin Prada
 * Project 2             : I Love Baseball
 * CLASS                 : CS8
 * SECTION               : MW 9:45-11:10AM TTH 9:45-11:50AM
 * Due Date              : 12/5/19
 * *************************************/

#include "mainwindow.h"
#include <QApplication>
#include <iostream>
using namespace std;
/***************************************
 * Baseball
 * --------------------------------------------------------------------
 *  The function of this program is to provide the user with a convenient
 *      interface that allows them to plan a trip between various basebell
 *      stadiums. The  program can alo track souvenirs purchased during the
 *      trip and display a map of all stadiums visited. An admin can modify,
 *      add, or delete stadiums or souvenirs.
 * --------------------------------------------------------------------
 *  INPUT:
 *      a - qt application
 *      w - window object
 * OUTPUT:
 *      None
 * *************************************/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);     // IN & OUT - qt application
    MainWindow w;                   // IN & OUT - graphics object
    w.show();
    return a.exec();
}
