#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWidget;

class MainWindow : public QMainWindow {
Q_OBJECT
private:
    MainWidget* mainWidget;

    void setupMenu();

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;
};

#endif // MAINWINDOW_H
