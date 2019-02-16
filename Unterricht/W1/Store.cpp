//
// Created by Nicolas Haenni on 2019-02-02.
//

#include "Store.h"
#include <QDebug>

Store* Store::instance = nullptr;

Store::Store() = default;

Store* Store::getInstance() {
    if (instance == nullptr) {
        instance = new Store();
    }
    return instance;
}

void Store::setCC(CreditCard* cc) {
    this->cc = cc;
}

CreditCard* Store::getCC() {
    return this->cc;
}
