#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class QMouseEvent;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWIDGET_H
