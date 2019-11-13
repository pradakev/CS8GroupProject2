#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "files.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readStadiums(graph, "stadiumInfo.txt");
    readEdges(graph, "stadiumDistances.txt");

}

MainWindow::~MainWindow()
{
    delete ui;
}

