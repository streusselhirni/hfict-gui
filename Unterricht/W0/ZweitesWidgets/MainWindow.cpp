//
// Created by Nicolas Haenni on 2019-01-19.
//

#include <QStatusBar>
#include "MainWindow.h"
#include "Widget.h"

MainWindow::MainWindow() {
    this->w = new Widget();
    this->setCentralWidget(w);
    this->statusBar()->showMessage("Sichere Verbindung hergestellt.");

    // TODO: Add Menubar
}
