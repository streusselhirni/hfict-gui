//
// Created by Nicolas Haenni on 2019-02-22.
//

#ifndef PWGENERATOR_MAINWIDGET_H
#define PWGENERATOR_MAINWIDGET_H


#include <QWidget>
#include <Vector>

class QSlider;
class QCheckBox;
class QLineEdit;

class MainWidget : public QWidget {
    Q_OBJECT;
private:
    void createLayout();
    QSlider *slider;
    QCheckBox *check1;
    QCheckBox *check2;
    QCheckBox *check3;
    QLineEdit *input;


    QString generatePassword();
    std::vector<char> specialChars = {'%', '!', '#', '@', '$', '*'};

public:
    MainWidget();
    ~MainWidget();


public slots:
    void calculate(int value);
};


#endif //PWGENERATOR_MAINWIDGET_H
