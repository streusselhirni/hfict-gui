#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class QLCDNumber;

class QPushButton;

class QSpinBox;

class QCheckBox;

class WorkerThread;

class MainWidget : public QWidget
{
Q_OBJECT

private:
    QLCDNumber * lcd;
    QPushButton* startBtn;
    QPushButton* reset;
    QSpinBox   * spinBoxQtyLoops;
    QSpinBox   * spinBoxQtyThreads;
    QCheckBox  * checkBox;
    QMutex * mutex;

    WorkerThread** threads;
    int counter;
    int loopsPerThread;
    int amountOfThreads;

    void createLayout();
    void setupEventHandling();

public:
    explicit MainWidget(QWidget* parent = nullptr);
    ~MainWidget() override;
    void incrementCounter();

public slots:
    void resetValues();
    void startThreads();
};

#endif // MAINWIDGET_H