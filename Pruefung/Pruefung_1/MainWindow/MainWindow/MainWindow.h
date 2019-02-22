#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    MainWidget *mw;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
