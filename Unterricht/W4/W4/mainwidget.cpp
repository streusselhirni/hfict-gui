#include "mainwidget.h"

#include <QDebug>
#include <QMouseEvent>
#include <QMediaPlayer>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    this->test = new QMediaPlayer();
}

MainWidget::~MainWidget()
{

}

void MainWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << event->x() << ":" << event->y();
}
