#include "mainwindow.h"
#include "MainWidget.h"
#include <QStatusBar>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    this->mainwidget = new MainWidget();
    this->status     = new QStatusBar();
    this->status->showMessage("No file selected");

    this->setCentralWidget(mainwidget);
    this->setStatusBar(status);

    QObject::connect(mainwidget, &MainWidget::fileSelected, this, &MainWindow::onFileSelected);
}

MainWindow::~MainWindow() {

}

void MainWindow::onFileSelected(const QString& file) {
    if (file.isEmpty()) this->status->showMessage("No file selected");
    else this->status->showMessage(file);
}
