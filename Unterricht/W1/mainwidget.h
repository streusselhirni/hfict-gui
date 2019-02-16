#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "creditcard.h"

class QComboBox;

class QLineEdit;

class QPushButton;

class MainWidget : public QWidget {
    Q_OBJECT;
public:
    MainWidget();
    ~MainWidget();

private:
    MainWidget(const MainWidget& obj);
    MainWidget operator=(const MainWidget& obj);

    void createLayout();
    void setDefaultValues();
    void setupEventHandling();

    QComboBox* monthBox;
    QComboBox* yearBox;

    QPushButton* checkButton;
    QPushButton* clearButton;

    QLineEdit** blockInput;

public slots:
    void getData();
    void onResultUpdate(CreditCard&);
};

#endif // MAINWIDGET_H

