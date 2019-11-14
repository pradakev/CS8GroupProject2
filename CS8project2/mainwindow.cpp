#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "files.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    readStadiums(g, "stadiumInfo.txt");
    readEdges(g, "stadiumDistances.txt");
    readSouvenirs(s, "SouvenirList.txt");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::gotoPage(int pg)
{
    ui->stackedWidget->setCurrentIndex(pg);
}

//MAIN MENU

//start trip for customer button pushed
void MainWindow::on_customerPushButtonMenu_clicked()
{
    gotoPage(1);

}

//void MainWindow::on_customerPushButtonMenu_clicked()
//{
//    gotoPage(1);

//}

//admin button
void MainWindow::on_adminPushButtonMain_clicked()
{
    gotoPage(5);
}


//CUSTOMER MAIN MENU

//customer presses on done to go back to main.
void MainWindow::on_customerDoneButton_clicked()
{
    gotoPage(0);
}

//show map. goes to different tab
void MainWindow::on_showMapTripButton_clicked()
{
    gotoPage(3);
}

void MainWindow::on_trackSouvenirsButton_clicked()
{
    gotoPage(4);
}

//MAP Page

//Done button on Map
void MainWindow::on_mapPgDoneButton_clicked()
{
    gotoPage(1);
}

//ADMIN PG

//donebutton
void MainWindow::on_adminPgDoneButton_clicked()
{
    gotoPage(0);
}




//SOUVENIRS PAGE

//done button
void MainWindow::on_souvenirsDoneButton_clicked()
{
    gotoPage(1);
}


//STADIUMS
void MainWindow::setStadiumTextBrowser(string stadiumTemp)
{
    gotoPage(2);
    stadium temp; //temp stadium
    temp = g.getStadiumInfo(stadiumTemp);
    string info = temp.getAllInfo();
    QString a;
    a = QString::fromStdString(info);
    ui->stadiumInfoTextBrowser->setText(a);
}
void MainWindow::on_pushButton_4_clicked()
{
    gotoPage(2);
    stadium LA; //temp stadium
    LA = g.getStadiumInfo("Dodger Stadium");
    string info = LA.getAllInfo();
    QString a;
    a = QString::fromStdString(info);
    ui->stadiumInfoTextBrowser->setText(a);
}

void MainWindow::on_stadiumInfoDoneButton_clicked()
{
    gotoPage(1);
}

void MainWindow::on_exitMainButton_clicked()
{
    exit(0);
}

void MainWindow::on_pushButton_8_clicked()
{
    //angels
    setStadiumTextBrowser("Angels Stadium of Anaheim");
}

void MainWindow::on_pushButton_9_clicked()
{
    setStadiumTextBrowser("Kauffman Stadium");
}

void MainWindow::on_pushButton_11_clicked()
{
    setStadiumTextBrowser("Busch Stadium");
}

void MainWindow::on_pushButton_10_clicked()
{
    setStadiumTextBrowser("Citi Field");
}

void MainWindow::on_stadiumsByNamButton_clicked()
{
    gotoPage(2);

}

void MainWindow::on_gobacktomainpage_clicked()
{
    gotoPage(0);
}

void MainWindow::on_stadiumTable_clicked()
{
    gotoPage(7);
}
