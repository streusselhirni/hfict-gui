#ifndef CCCHECKER_STORE_H
#define CCCHECKER_STORE_H

#include <QObject>
#include <QString>
#include "creditcard.h"

class Store : QObject {
    Q_OBJECT;
private:
    Store();
    CreditCard* cc;
    static Store* instance;
public:
    static Store* getInstance();
    void setCC(CreditCard* cc);
    CreditCard* getCC();
};


#endif //CCCHECKER_STORE_H
