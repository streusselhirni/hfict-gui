#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QWidget;

class QPushButton;

class Painting;

class Animation;

class MainWindow : public QMainWindow {
Q_OBJECT
private:
    QWidget *w;
    QPushButton *startBtn;
    QPushButton *animBtn;
    Painting *p;
    Animation *a;

    void setupLayout();
    void setupEvents();
    void setupThread();
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

public slots:
    void animate();
};

#endif // MAINWINDOW_H
