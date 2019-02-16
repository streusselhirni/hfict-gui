#include <QDebug>
#include "Controller.h"
#include "Store.h"

Controller::Controller() = default;

void Controller::onButtonClicked() {
    qDebug() << Store::getInstance()->getText();
}
