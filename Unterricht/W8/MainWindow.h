#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>

class Mandelbrot;

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Mandelbrot* mw;
};

#endif // MAINWIDGET_H
