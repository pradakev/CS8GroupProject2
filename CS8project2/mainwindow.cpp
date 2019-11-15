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

void MainWindow::on_stadiumTableInfo_clicked()
{
    gotoPage(7);

    List <stadium> printThis = g.getStadiumList();

    if (ui->GrassSurface->currentIndex() == 1){
        printThis = g.getStadiumWithGrassField();
    }
    node<stadium>* w = printThis.Begin();

    ui->tableWidget_2->setColumnCount(0);

    for (int i = 0; i < 5; i++){
        ui->tableWidget_2->insertColumn(i);
    }
    ui->tableWidget_2->setHorizontalHeaderItem(0, new QTableWidgetItem("Stadium Name"));
    ui->tableWidget_2->setHorizontalHeaderItem(1, new QTableWidgetItem("Team Name"));
    ui->tableWidget_2->setHorizontalHeaderItem(2, new QTableWidgetItem("League"));
    ui->tableWidget_2->setHorizontalHeaderItem(3, new QTableWidgetItem("Date Founded"));
    ui->tableWidget_2->setHorizontalHeaderItem(4, new QTableWidgetItem("Field Surface"));

    int count;

    ui->tableWidget_2->setRowCount(0);

    while(w)
    {
        count = ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());

        QTableWidgetItem * stadiumName = new QTableWidgetItem(QString::fromStdString(w->_item.getStadiumName()));
        QTableWidgetItem * teamName = new QTableWidgetItem(QString::fromStdString(w->_item.getTeamName()));
        QTableWidgetItem * leagueType = new QTableWidgetItem(QString::fromStdString(w->_item.getType()));
        QTableWidgetItem * openDate = new QTableWidgetItem(QString::fromStdString(w->_item.getOpenDate()));
        QTableWidgetItem * fieldSurface = new QTableWidgetItem(QString::fromStdString(w->_item.getFieldSurface()));


        stadiumName->setTextAlignment(Qt::AlignCenter);
        teamName->setTextAlignment(Qt::AlignCenter);
        leagueType->setTextAlignment(Qt::AlignCenter);
        openDate->setTextAlignment(Qt::AlignCenter);
        fieldSurface->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget_2->setItem(count, 0, stadiumName);
        ui->tableWidget_2->setItem(count, 1, teamName);
        ui->tableWidget_2->setItem(count, 2, leagueType);
        ui->tableWidget_2->setItem(count, 3, openDate);
        ui->tableWidget_2->setItem(count, 4, fieldSurface);

        w = w->next;
    }

    ui->tableWidget_2->horizontalHeader()->
            setSectionResizeMode(QHeaderView::ResizeToContents);

    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget_2->setSortingEnabled(true);
}

void MainWindow::on_backtoMain_clicked()
{
    gotoPage(0);
}

void MainWindow::on_GrassSurface_currentIndexChanged(int index)
{
    on_stadiumTableInfo_clicked();
}
