#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graph.h"
#include <QMainWindow>

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

    void on_showMapTripButton_clicked();

    void on_souvenirsDoneButton_clicked();

    void on_trackSouvenirsButton_clicked();



    void on_pushButton_4_clicked();

    void on_stadiumInfoDoneButton_clicked();

private:
    graph graph;
    Ui::MainWindow *ui;

    //GRAPH
    graph g;

};
#endif // MAINWINDOW_H
