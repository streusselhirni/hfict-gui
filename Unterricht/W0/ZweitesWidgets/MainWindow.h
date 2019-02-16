//
// Created by Nicolas Haenni on 2019-01-19.
//

#ifndef ZWEITESWIDGET_MAINWINDOW_H
#define ZWEITESWIDGET_MAINWINDOW_H


#include <QMainWindow>

class Widget;

class MainWindow: public QMainWindow {
public:
    MainWindow();
private:
    Widget *w;
};


#endif //ZWEITESWIDGET_MAINWINDOW_H
