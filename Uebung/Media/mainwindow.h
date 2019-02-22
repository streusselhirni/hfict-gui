#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWidget;
class QStatusBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    MainWidget *mainwidget;
    QStatusBar *status;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

public slots:
    void onFileSelected(const QString&);
};

#endif // MAINWINDOW_H
