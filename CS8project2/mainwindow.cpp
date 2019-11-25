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

//    cout << g.Dijkstras(g.getStadiumInfo("Angels Stadium of Anaheim"));
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


void MainWindow::on_planTripButton_clicked()
{
    gotoPage(6);
}

void MainWindow::on_pushButton_31_clicked()
{
    gotoPage(1);
}

void MainWindow::on_allStadiumsButton_clicked()
{
//    node<stadium>* all = this->g.getStadiumList().Begin();
//    while(all){

//        ui->textBrowser_3->setText(QString::fromStdString(all->_item.getStadiumName()));
//        ui->textBrowser_3->setText(QString::fromStdString("\n"));
//        all = all->next;
//    }
}

void MainWindow::on_pushButton_38_clicked()
{
    gotoPage(4);
}

void MainWindow::on_pushButton_39_clicked()
{
    gotoPage(3);
}

//MODIFICATION FOR STADIUMS
void MainWindow::on_pushButton_clicked()
{
    gotoPage(8);

    List <stadium> printThis = g.getStadiumList();

    node<stadium>* w = printThis.Begin();

    ui->modificationTable->setColumnCount(0);

    for (int i = 0; i < 8; i++){
        ui->modificationTable->insertColumn(i);
    }
    ui->modificationTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Stadium Name"));
    ui->modificationTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Team Name"));
    ui->modificationTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Address"));
    ui->modificationTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Box Office"));
    ui->modificationTable->setHorizontalHeaderItem(4, new QTableWidgetItem("Date Founded"));
    ui->modificationTable->setHorizontalHeaderItem(5, new QTableWidgetItem("Capacity"));
    ui->modificationTable->setHorizontalHeaderItem(6, new QTableWidgetItem("League"));
    ui->modificationTable->setHorizontalHeaderItem(7, new QTableWidgetItem("Field Surface"));

    int count;

    ui->modificationTable->setRowCount(0);

    while(w)
    {
        count = ui->modificationTable->rowCount();
        ui->modificationTable->insertRow(ui->modificationTable->rowCount());

        QTableWidgetItem * stadiumName = new QTableWidgetItem(QString::fromStdString(w->_item.getStadiumName()));
        QTableWidgetItem * teamName = new QTableWidgetItem(QString::fromStdString(w->_item.getTeamName()));
        QTableWidgetItem * Address = new QTableWidgetItem(QString::fromStdString(w->_item.getAddress()));
        QTableWidgetItem * boxOffice = new QTableWidgetItem(QString::fromStdString(w->_item.getPhone()));
        QTableWidgetItem * openDate = new QTableWidgetItem(QString::fromStdString(w->_item.getOpenDate()));
        QTableWidgetItem * capacity = new QTableWidgetItem(QString::fromStdString(w->_item.getCapacity()));
        QTableWidgetItem * leagueType = new QTableWidgetItem(QString::fromStdString(w->_item.getType()));
        QTableWidgetItem * fieldSurface = new QTableWidgetItem(QString::fromStdString(w->_item.getFieldSurface()));

        stadiumName->setTextAlignment(Qt::AlignCenter);
        teamName->setTextAlignment(Qt::AlignCenter);
        Address->setTextAlignment(Qt::AlignCenter);
        boxOffice->setTextAlignment(Qt::AlignCenter);
        openDate->setTextAlignment(Qt::AlignCenter);
        capacity->setTextAlignment(Qt::AlignCenter);
        leagueType->setTextAlignment(Qt::AlignCenter);
        fieldSurface->setTextAlignment(Qt::AlignCenter);

        ui->modificationTable->setItem(count, 0, stadiumName);
        ui->modificationTable->setItem(count, 1, teamName);
        ui->modificationTable->setItem(count, 2, Address);
        ui->modificationTable->setItem(count, 3, boxOffice);
        ui->modificationTable->setItem(count, 4, openDate);
        ui->modificationTable->setItem(count, 5, capacity);
        ui->modificationTable->setItem(count, 6, leagueType);
        ui->modificationTable->setItem(count, 7, fieldSurface);


        w = w->next;
    }

    ui->modificationTable->horizontalHeader()->
            setSectionResizeMode(QHeaderView::ResizeToContents);

    ui->modificationTable->sortItems(0);
}

void MainWindow::on_modAddNewButton_clicked()
{
    ui->modificationTable->insertRow(ui->modificationTable->rowCount());
    ui->modificationTable->scrollToBottom();

}

void MainWindow::on_modDoneButton_clicked()
{
    QMessageBox message;

    List<stadium> newList;
    stadium toAdd;

    for (int i = 0; i < ui->modificationTable->rowCount(); i++){
        if (ui->modificationTable->item(i,0)->text() == QString("")){
            message.setWindowTitle("Error!");
            message.setText("Error occur. Cannot remove stadium.");
            message.setStandardButtons(QMessageBox::Ok);
            message.setIcon(QMessageBox::Icon::Warning);
            if (message.exec()){
                message.close();
                gotoPage(5);
                return;
            }
        }else{
            toAdd.setName(ui->modificationTable->item(i,0)->text().toStdString());
            toAdd.setTeamName(ui->modificationTable->item(i,1)->text().toStdString());
            toAdd.setAddress(ui->modificationTable->item(i,2)->text().toStdString());
            toAdd.setphone(ui->modificationTable->item(i,3)->text().toStdString());
            toAdd.setOpenDate(ui->modificationTable->item(i,4)->text().toStdString());
            toAdd.setCapacity(ui->modificationTable->item(i,5)->text().toStdString());
            toAdd.setType(ui->modificationTable->item(i,6)->text().toStdString());
            toAdd.setFieldSurface(ui->modificationTable->item(i,7)->text().toStdString());
            newList.InsertAfter(toAdd,newList.End());
        }
    }

    message.setWindowTitle("Confirmation");
    message.setText("Are you sure you want to make these changes?");
    message.setStandardButtons(QMessageBox::Yes);
    message.addButton(QMessageBox::No);
    message.setDefaultButton(QMessageBox::No);
    message.setIcon(QMessageBox::Icon::Question);

    if(message.exec() == QMessageBox::Yes){
        this->g.stadiums = newList;
        ui->textBrowser_2->setText(QString("Stadium list modified"));
        message.close();
        gotoPage(5);
    }else {
        message.close();
        gotoPage(5);
    }
}

//MODIFICATION FOR SOUVENIRS
void MainWindow::on_pushButton_3_clicked()
{
    gotoPage(9);

    ui->modSouvenirTable->setColumnCount(0);

    for (int i = 0; i < 2; i++){
        ui->modSouvenirTable->insertColumn(i);
    }
    ui->modSouvenirTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->modSouvenirTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Price"));

    int count;

    ui->modSouvenirTable->setRowCount(0);


    for(int i = 0; i < s.getSize(); i++)
    {
        count = ui->modSouvenirTable->rowCount();
        ui->modSouvenirTable->insertRow(ui->modSouvenirTable->rowCount());

        QTableWidgetItem * souvenirName = new QTableWidgetItem(QString::fromStdString(s[i].getName()));
        QTableWidgetItem * Price = new QTableWidgetItem(QString::fromStdString(s[i].getPrice()));

        souvenirName->setTextAlignment(Qt::AlignCenter);
        Price->setTextAlignment(Qt::AlignCenter);

        ui->modSouvenirTable->setItem(count, 0, souvenirName);
        ui->modSouvenirTable->setItem(count, 1, Price);
    }

    ui->modSouvenirTable->horizontalHeader()->
            setSectionResizeMode(QHeaderView::ResizeToContents);

    ui->modSouvenirTable->sortItems(0);
}

void MainWindow::on_modSDoneButton_clicked()
{
    souvenirs newList;
    souvenir toAdd;

    for (int i = 0; i < ui->modSouvenirTable->rowCount(); i++){
        if (ui->modSouvenirTable->item(i,0)->text() != QString("")){
            toAdd.setName(ui->modSouvenirTable->item(i,0)->text().toStdString());
            toAdd.setPrice(ui->modSouvenirTable->item(i,1)->text().toStdString());
            newList.addSouvenir(toAdd);
        }
    }
    QMessageBox message;
    message.setWindowTitle("Confirmation");
    message.setText("Are you sure you want to make these changes?");

    message.setStandardButtons(QMessageBox::Yes);
    message.addButton(QMessageBox::No);
    message.setDefaultButton(QMessageBox::No);

    message.setIcon(QMessageBox::Icon::Question);
    if(message.exec() == QMessageBox::Yes){
        this->s = newList;
        ui->textBrowser_2->setText(QString("Souvenir list modified"));
        message.close();
        gotoPage(5);
    }else {
        message.close();
        gotoPage(5);
    }
}

void MainWindow::on_modSAddNewButton_clicked()
{
    ui->modSouvenirTable->insertRow(ui->modSouvenirTable->rowCount());
    ui->modSouvenirTable->scrollToBottom();
}

