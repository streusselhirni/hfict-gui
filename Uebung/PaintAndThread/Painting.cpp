//
// Created by Nicolas Haenni on 2019-04-12.
//

#include <QPainter>
#include <QPoint>
#include <QDebug>
#include "Painting.h"

void Painting::paintEvent(QPaintEvent* e)
{
    QPainter p(this);
    p.setPen(QPen(Qt::red));
    p.drawLine(QPoint(x1, 10), QPoint(x2, 10));
}

Painting::Painting(QWidget *parent)
{
    this->setParent(parent);
    this->setFixedSize(300, 200);

    this->x1 = (this->width() / 2) + 10;
    this->x2 = (this->width() / 2) - 10;
    this->growing = true;
}

Painting::~Painting()= default;

void Painting::move()
{
    qDebug() << "Moved to " << x1 << " and " << x2;

    if (growing) {
        x1 += 10;
        x2 -= 10;

        if (x2 <= 40) growing = false;
    } else {
        x1 -= 10;
        x2 += 10;

        if (x2 >= 140) growing = true;
    }

    this->repaint();
}
