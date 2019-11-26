#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "files.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    readStadiums(g, "../CS8Project2/textFiles/stadiumInfo.txt");
    readEdges(g, "../CS8Project2/textFiles/stadiumDistances.txt");
    readSouvenirs(s, "../CS8Project2/textFiles/SouvenirList.txt");


    //Setup Push buttons
    ui->dodgerButton->setFixedSize(80, 55);
    ui->angelsButton->setFixedSize(80, 55);
    ui->sanDiegoButton->setFixedSize(80, 55);
    ui->oaklandAButton->setFixedSize(80, 55);

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
    ui->textBrowser_2->clear();
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
void MainWindow::on_dodgerButton_clicked()
{
    planTeamButtons("Dodger Stadium");
}

void MainWindow::on_stadiumInfoDoneButton_clicked()
{
    gotoPage(1);
}

void MainWindow::on_exitMainButton_clicked()
{
    saveStadiums(g, "../CS8Project2/textFiles/stadiumInfo.txt");
    saveSouvenirs(s, "../CS8Project2/textFiles/SouvenirList.txt");
    exit(-1);
}

void MainWindow::on_angelsButton_clicked()
{
    planTeamButtons("Angels Stadium of Anaheim");
}

void MainWindow::on_kansasCityButton_clicked()
{
    planTeamButtons("Kauffman Stadium");
}

void MainWindow::on_stLouisButton_clicked()
{
    planTeamButtons("Busch Stadium");
}

void MainWindow::on_nyMetsButton_clicked()
{
    planTeamButtons("Citi Field");
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



void MainWindow::on_gobacktomainpage_clicked()

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
    //Send-Convert string array of stadium names to stadium list

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
        ui->textBrowser_2->append(QString("Stadium list modified"));
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
        ui->textBrowser_2->append(QString("Souvenir list modified"));
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



void MainWindow::on_stadiumTable_clicked()
{
    gotoPage(7);

}

void MainWindow::on_stadiumInfoCheckBox_stateChanged(int arg1)
{
    if(ui->stadiumInfoCheckBox->isChecked())
    {
        ui->stadiumCheckBoxBrowser->setText("Select a stadium to see their info!");
    }
    else
    {
        ui->stadiumCheckBoxBrowser->setText("Check to select a stadiums' info.");
    }
}

//ORIGIN STADIUMS
void MainWindow::on_sanDiegoButton_clicked()
{
    //if stadiumInfo Checkbox
    if(ui->stadiumInfoCheckBox->isChecked())
        setStadiumTextBrowser("Petco Park");
    else
    {
        stadiumPathText += "Petco Park" + arrow;
        ui->plannedTripStadiumBrowser->setText(stadiumPathText);
    }
}

void MainWindow::on_sanFranciscoButton_clicked()
{
    //if stadiumInfo Checkbox
    if(ui->stadiumInfoCheckBox->isChecked())
        setStadiumTextBrowser("AT&T Park");
    else
    {
        stadiumPathText += "AT&T Park" + arrow;
        ui->plannedTripStadiumBrowser->setText(stadiumPathText);
    }
}

void MainWindow::on_oaklandAButton_clicked()
{
    //if stadiumInfo Checkbox
    if(ui->stadiumInfoCheckBox->isChecked())
        setStadiumTextBrowser("O.co Coliseum");
    else
    {
        stadiumPathText += "O.co Coliseum" + arrow;
        ui->plannedTripStadiumBrowser->setText(stadiumPathText);
    }
}

void MainWindow::on_seattleButton_clicked()
{
    planTeamButtons("SafeCo Field");
}

void MainWindow::on_coloradoButton_clicked()
{
    planTeamButtons("Coors Field");
}

void MainWindow::on_arizonaButton_clicked()
{
    planTeamButtons("Chase Field");
}

void MainWindow::planTeamButtons(string stadiumName)
{
    QString QStadiumName = QString::fromStdString(stadiumName);

    //If Stadium Info Checkbox checked, show INFO
    if(ui->stadiumInfoCheckBox->isChecked())
        setStadiumTextBrowser(stadiumName);

    else
    {
        //Makes sure to make client choose origin in CA
        if(sizeDreamList == 0 &&
                stadiumName != "Dodger Stadium" &&
                stadiumName != "Angels Stadium of Anaheim" &&
                stadiumName != "Petco Park" &&
                stadiumName != "AT&T Park" &&
                stadiumName != "O.co Coliseum")
        {
            ui->plannedTripStadiumBrowser->setText("Please choose a CA stadium"
                                                   "as your origin!");
            return;
        }
        //Add stadium name to array of stadiums for later
        dreamList[sizeDreamList] = stadiumName;
        sizeDreamList++;

        //Set Text Browser
        stadiumPathText += QStadiumName + arrow;
        ui->plannedTripStadiumBrowser->setText(stadiumPathText);
    }
}

void MainWindow::on_minnesotaButton_clicked()
{
    planTeamButtons("Target Field");
}

void MainWindow::on_texasRangersButton_clicked()
{
    planTeamButtons("Globe Life Park in Arlington");
}


void MainWindow::on_houstonButton_clicked()
{
    planTeamButtons("Minute Maid Park");
}

void MainWindow::on_milwaukeeButton_clicked()
{
    planTeamButtons("Miller Park");
}

void MainWindow::on_chicagoButton_clicked()
{
    planTeamButtons("Wrigley Field");
}

void MainWindow::on_chicagoWhiteSoxButton_clicked()
{
    planTeamButtons("US Cellular Field");
}

void MainWindow::on_cincinattiButton_clicked()
{
    planTeamButtons("Great America Ball Park");
}

void MainWindow::on_atlantaButton_clicked()
{
    planTeamButtons("Turner Field");
}

void MainWindow::on_clevelandButton_clicked()
{
    planTeamButtons("Progressive Field");
}

void MainWindow::on_tampaBayButton_clicked()
{
    planTeamButtons("Tropicana Field");
}

void MainWindow::on_floridaButton_clicked()
{
    planTeamButtons("Marlins Park");
}

void MainWindow::on_pittsburghButton_clicked()
{
    planTeamButtons("PNC Park");
}

void MainWindow::on_washingtonButton_clicked()
{
    planTeamButtons("Nationals Park");
}

void MainWindow::on_torontoButton_clicked()
{
    planTeamButtons("Rogers Centre");
}

void MainWindow::on_detroitButton_2_clicked()
{
    planTeamButtons("Comerica Park");
}

void MainWindow::on_bostonButton_clicked()
{
    planTeamButtons("Fenway Park");
}

void MainWindow::on_baltimoreButton_clicked()
{
    planTeamButtons("Oriole Park at Camden Yards");
}

void MainWindow::on_phillyButton_clicked()
{
    planTeamButtons("Citizens Bank Park");
}

void MainWindow::on_nyYankeesButton_clicked()
{
    planTeamButtons("Yankee Stadium");
}

void MainWindow::on_restartDreamList_clicked()
{
    QString restartTxt = "List Cleared. Go ahead and start planning your new"
                         "dream vacation!";
    ui->plannedTripStadiumBrowser->setText(restartTxt);
    sizeDreamList = 0;
}
