#include "mainwindow.h"
#include "MainWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->mainWidget = new MainWidget();
    this->setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{

}