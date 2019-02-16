#ifndef WOCHE3_CONTROLLER_H
#define WOCHE3_CONTROLLER_H

#include <QWidget>

#include "mainwidget.h"

class MainWidget;

class Controller : public QObject {
Q_OBJECT;
public:
    explicit Controller();
public slots:
    void onButtonClicked();
};


#endif //WOCHE3_CONTROLLER_H
