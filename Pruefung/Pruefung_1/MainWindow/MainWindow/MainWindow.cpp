#include "MainWindow.h"
#include "MainWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->mw = new MainWidget();
    this->setCentralWidget(mw);
    this->setFixedSize(640, 480);
}

MainWindow::~MainWindow()
{

}
