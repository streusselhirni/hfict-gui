#include "MainWindow.h"
#include "MainWidget.h"
#include <QApplication>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    this->mainWidget = new MainWidget();
    this->setWindowTitle("Threads");
    this->setFixedSize(600, 200);

    this->setCentralWidget(mainWidget);
}

MainWindow::~MainWindow() = default;