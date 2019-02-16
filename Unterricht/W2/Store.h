#ifndef WOCHE3_ZENTRALE_H
#define WOCHE3_ZENTRALE_H

#include <QString>

class Store {
private:
    Store();
    static Store* instance;
    QString text;
public:
    static Store* getInstance();
    void setText(QString text);
    QString getText();
};


#endif //WOCHE3_ZENTRALE_H
