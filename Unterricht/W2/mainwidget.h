#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class QPushButton;

class QLineEdit;

class MainWidget : public QWidget {
public:
    MainWidget();
    ~MainWidget() override;

private:
    QPushButton* button;
    QLineEdit* input;
};

#endif // MAINWIDGET_H
