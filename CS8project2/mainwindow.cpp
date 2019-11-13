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
    gotoPage(4);
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
    gotoPage(2);
}

void MainWindow::on_trackSouvenirsButton_clicked()
{
    gotoPage(3);
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



void MainWindow::on_pushButton_4_clicked()
{
    gotoPage(2);
    stadium LA;
    LA = g.getStadiumInfo("Dodger Stadium");
    stringstream ss;

    ss << LA.getAllInfo() << endl;
    string info = ss.str();
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
    this->close();
}
