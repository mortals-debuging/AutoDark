#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug("hello world");
    ThemeSwitcher* pq = new ThemeSwitcher();
    pq->dbusConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

