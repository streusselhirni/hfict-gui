#include "Store.h"

Store::Store() = default;

Store* Store::instance = nullptr;

Store* Store::getInstance() {
    if (instance == nullptr) {
        instance = new Store();
    }
    return instance;
}

void Store::setText(QString text) {
    this->text = text;
}

QString Store::getText() {
    return this->text;
}
