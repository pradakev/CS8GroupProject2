#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graph.h"
#include "souvenir.h"
#include <QMainWindow>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Function that changes tab of StackedWidget to index passed in
    void gotoPage(int pg);

private slots:
    void on_customerPushButtonMenu_clicked();

    void on_customerDoneButton_clicked();

    void on_mapPgDoneButton_clicked();

    void on_adminPgDoneButton_clicked();

    void on_adminPushButtonMain_clicked();

    void on_souvenirsDoneButton_clicked();


    void on_pushButton_4_clicked();

    void on_stadiumInfoDoneButton_clicked();

    void on_exitMainButton_clicked();


    void on_pushButton_8_clicked();

    //helper function
    void setStadiumTextBrowser(string stadiumTemp);
    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_stadiumsByNamButton_clicked();

    void on_stadiumTableInfo_clicked();

//    void on_backtoMain_clicked();

    void on_GrassSurface_currentIndexChanged(int index);


    void on_planTripButton_clicked();

    void on_pushButton_31_clicked();


    void on_allStadiumsButton_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_clicked();

    void on_modDoneButton_clicked();

    void on_pushButton_3_clicked();

    void on_modAddNewButton_clicked();

    void on_modSDoneButton_clicked();

    void on_modSAddNewButton_clicked();

    void on_gobacktomainpage_clicked();

    void on_stadiumTable_clicked();

private:
    Ui::MainWindow *ui;

    //GRAPH
    graph g;

    //SOUVENIR
    souvenirs s;


};
#endif // MAINWINDOW_H
