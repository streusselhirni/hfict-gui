//
// Created by Nicolas Haenni on 2019-01-26.
//

#ifndef CCCHECKER_EVENTHANDLER_H
#define CCCHECKER_EVENTHANDLER_H

#include <QObject>
#include <QDebug>
#include "creditcard.h"

class Controller : public QObject {
Q_OBJECT;
public:
    static bool validate();

public slots:
    void onCCReceived();

signals:
    void retrieveGuiData(CreditCard&);
    void updateResult(CreditCard&);
};


#endif //CCCHECKER_EVENTHANDLER_H
