//
// Created by Nicolas Haenni on 2019-01-19.
//

#ifndef W0_WIDGET_H
#define W0_WIDGET_H


#include <QWidget>

class QLabel;

class QCheckBox;

class QPushButton;

class Widget : public QWidget {
public:
    Widget();
    ~Widget() override;
private:
    QCheckBox  * cb1;
    QCheckBox  * cb2;
    QCheckBox  * cb3;
    QPushButton* cancelBtn;
    QPushButton* okBtn;
};


#endif //W0_WIDGET_H
