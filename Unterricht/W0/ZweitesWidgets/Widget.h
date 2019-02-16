//
// Created by Nicolas Haenni on 2019-01-19.
//

#ifndef ZWEITESWIDGET_WIDGET_H
#define ZWEITESWIDGET_WIDGET_H


#include <QWidget>
class QPushButton;
class QLineEdit;
class QLabel;

class Widget: public QWidget {
public:
    Widget();
    ~Widget();
private:
    QLineEdit *le1;
    QLineEdit *le2;
    QLineEdit *le3;
    QLineEdit *le4;
    QPushButton *checkBtn;
    QPushButton *clearBtn;
    QLabel *answerLbl;
    void check();
};


#endif //ZWEITESWIDGET_WIDGET_H
