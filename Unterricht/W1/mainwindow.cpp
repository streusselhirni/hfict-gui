#include "mainwindow.h"
#include "mainwidget.h"

MainWindow::MainWindow() {
    mainWidget = new MainWidget();
    this->setCentralWidget(mainWidget);
}

MainWindow::~MainWindow() {
    delete mainWidget;
}
