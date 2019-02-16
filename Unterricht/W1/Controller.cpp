//
// Created by Nicolas Haenni on 2019-01-26.
//

#include "Controller.h"
#include "Store.h"

void Controller::onCCReceived() {
    this->validate();
}

bool Controller::validate() {
    CreditCard* cc = Store::getInstance()->getCC();

    return false;
}
