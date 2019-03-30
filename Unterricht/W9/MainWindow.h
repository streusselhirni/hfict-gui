#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;

class QSlider;

class Engine;

class Animation;

class MainWindow : public QMainWindow
{
Q_OBJECT

private:
    QPushButton* buttonAnimationSwitch;
    QPushButton* buttonAnimationStepper;
    QSlider    * slider;
    Engine     * engine;
    Animation  * animation;
    void setupLayout();
    void setupSignalProviderThread();
    void setupConnections();

private slots:
    void buttonToggled();
    void buttonAnimationStepperClicked();

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;
};

#endif // MAINWINDOW_H
