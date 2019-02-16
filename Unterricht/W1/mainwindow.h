#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWidget;

class MainWindow : public QMainWindow {
private:
    MainWidget* mainWidget;

public:
    MainWindow();
    ~MainWindow();
};

#endif // MAINWINDOW_H

