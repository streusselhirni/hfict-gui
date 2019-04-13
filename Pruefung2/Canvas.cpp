#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
#include <QString>
#include <QPoint>
#include "canvas.h"

Canvas::Canvas(QWidget* parent) : QWidget(parent)
{
    this->setMinimumSize(QSize(600, 600));
    this->setMaximumSize(QSize(600, 600));
    direction = "N";
    ballon    = new QPoint(300, 300);
}

Canvas::~Canvas()
{
    delete ballon;
}

void Canvas::updateDirection(QString s)
{
    if (direction.length() < 1)
        return;
    direction = s[0];
    qDebug() << "Switch Direction:" << direction;
}

void Canvas::moveBallon()
{
    qDebug() << "Move clicked";
    if (direction.length() < 1)
        return;
    /* ***********************************************
     * Ändern Sie die Koordinaten von QPoint* ballon
     * **********************************************/
    switch (direction.toStdString()[0]) {
        case 'N':
            // HIER den Ballon nach Norden bewegen um den Betrag 'pixelPerFrame'
            if (ballon->y() - 35 >= 0) ballon->setY(ballon->y() - this->pixelPerFrame);
            break;
        case 'O':
            // HIER den Ballon nach Osten bewegen um den Betrag 'pixelPerFrame'
            if (ballon->x() + 35 <= this->width()) ballon->setX(ballon->x() + this->pixelPerFrame);
            break;
        case 'S':
            // HIER den Ballon nach Süden bewegen um den Betrag 'pixelPerFrame'
            if (ballon->y() + 80 <= this->height()) ballon->setY(ballon->y() + this->pixelPerFrame);
            break;
        case 'W':
            // HIER den Ballon nach Westen bewegen um den Betrag 'pixelPerFrame'
            if (ballon->x() - 35 >= 0) ballon->setX(ballon->x() - this->pixelPerFrame);
            break;
        default:
            break;
    }
    qDebug() << "Moved the Ballon towards:" << direction
             << "(x=" << ballon->rx()
             << "y=" << ballon->ry() << ")";

    this->repaint();
}

void Canvas::paintEvent(QPaintEvent* e)
{
    QPainter* p = new QPainter(this);
    QFont f;
    f.setPixelSize(30);
    p->setFont(f);
    p->setPen(Qt::gray);

    /* ***********************************************
     * Zeichnen Sie hier die Kompass Windrose (statisch)
     * **********************************************/
    p->drawEllipse(0, 0, this->width(), this->height());
    p->drawText(QRect(0, 10, this->width(), 30), Qt::AlignCenter, "N");
    p->drawText(QRect(this->width() - 30, 0, 30, this->height()), Qt::AlignVCenter, "O");
    p->drawText(QRect(0, this->height() - 40, this->width(), 25), Qt::AlignCenter, "S");
    p->drawText(QRect(5, 0, 30, this->height()), Qt::AlignVCenter, "W");

    /* ***********************************************
     * Zeichnen Sie hier den Ballon (an aktueller Position)
     * **********************************************/
    QPen   pen(Qt::black, 2);
    QBrush brushBalloon(Qt::red, Qt::SolidPattern);
    QBrush brushBottom(Qt::darkGray, Qt::Dense5Pattern);
    p->setPen(pen);
    p->setBrush(brushBottom);

    QPoint basketTopLeft(ballon->x() - 10, ballon->y() + 50);
    QPoint basketTopRight(ballon->x() + 10, ballon->y() + 50);
    QPoint ballonLeft(ballon->x() - 30, ballon->y());
    QPoint ballonRight(ballon->x() + 30, ballon->y());

    p->drawRect(basketTopLeft.x(), basketTopLeft.y(), 20, 20);
    p->drawLine(basketTopLeft, ballonLeft);
    p->drawLine(basketTopRight, ballonRight);
    p->setBrush(brushBalloon);
    p->drawEllipse(*ballon, 30, 30);
}
