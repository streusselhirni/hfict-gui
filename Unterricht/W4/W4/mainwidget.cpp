#include "mainwidget.h"

#include <QDebug>
#include <QMouseEvent>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
}

MainWidget::~MainWidget()
{

}

void MainWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << event->x() << ":" << event->y();
}
