#include "creditcard.h"

QString CreditCard::getMonth() const {
    return this->month;
}

void CreditCard::setMonth(QString value) {
    this->month = value;
}

int CreditCard::getYear() const {
    return this->year;
}

void CreditCard::setYear(int value) {
    this->year = value;
}

int CreditCard::getValidationStatus() const {
    return this->validationStatus;
}

void CreditCard::setValidationStatus(int value) {
    this->validationStatus = value;
}

void CreditCard::setNumber(QString value) {
    this->number = value;
}

QString CreditCard::getNumber() {
    return this->number;
}

QString CreditCard::getType() const {
    return this->type;
}

void CreditCard::setType(const QString value) {
    this->type = value;
}
