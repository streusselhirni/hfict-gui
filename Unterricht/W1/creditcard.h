#ifndef CREDITCARD_H
#define CREDITCARD_H

#include<QString>

class CreditCard {
private:
    // input values
    QString number;
    QString month;
    int     year;

    // output values
    int     validationStatus;
    QString type;

public:
    void setNumber(QString value);
    QString getNumber();
    QString getMonth() const;
    void setMonth(QString value);
    int getYear() const;
    void setYear(int value);
    QString getType() const;
    void setType(const QString value);
    int getValidationStatus() const;
    void setValidationStatus(int value);
};

// Validate: https://www.freeformatter.com/credit-card-number-generator-validator.html

#endif // CREDITCARD_H
