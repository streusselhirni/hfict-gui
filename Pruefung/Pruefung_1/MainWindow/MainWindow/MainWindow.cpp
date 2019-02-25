#include "MainWindow.h"
#include "MainWidget.h"
#include <QApplication>
#include <QMenuBar>

MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent) {
    this->mainWidget = new MainWidget();
    this->setWindowTitle("ImageViewer");
    this->setupMenu();

    this->setCentralWidget(mainWidget);
}

MainWindow::~MainWindow() = default;

void MainWindow::setupMenu() {
    QMenuBar* menuBar = this->menuBar();

    QMenu* fileMenu = new QMenu(tr("&File"));

    QAction* loadAction = fileMenu->addAction("Load");
    QObject::connect(loadAction, SIGNAL(triggered()), this->mainWidget, SLOT(load()));

    QAction* exitAction = fileMenu->addAction("Close");
    QObject::connect(exitAction, SIGNAL(triggered()), QCoreApplication::instance(), SLOT(quit()));

    menuBar->addMenu(fileMenu);
}
