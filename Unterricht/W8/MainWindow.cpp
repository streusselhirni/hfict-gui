#include "MainWindow.h"
#include "Mandelbrot.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->mw = new Mandelbrot;
    this->setWindowTitle("Mandelbrot");
    this->setCentralWidget(mw);
};

MainWindow::~MainWindow() = default;
