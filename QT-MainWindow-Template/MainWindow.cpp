#include "MainWindow.h"
#include "MainWidget.h"
#include <QApplication>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    this->mainWidget = new MainWidget();
    this->setWindowTitle("Woche9");

    this->setCentralWidget(mainWidget);
}

MainWindow::~MainWindow() = default;