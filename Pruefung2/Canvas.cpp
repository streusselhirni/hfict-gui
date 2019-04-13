#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
#include <QString>
#include <QPoint>
#include "canvas.h"

Canvas::Canvas(QWidget* parent) : QWidget(parent)
{
    this->setMinimumSize(QSize(400, 400));
    this->setMaximumSize(QSize(400, 400));
    direction = "N";
    ballon    = new QPoint(200, 200);
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
    if (direction.length() < 1)
        return;
    /* ***********************************************
     * Ändern Sie die Koordinaten von QPoint* ballon
     * **********************************************/
    switch (direction.toStdString()[0]) {
        case 'N':
            // HIER den Ballon nach Norden bewegen um den Betrag 'pixelPerFrame'
            break;
        case 'O':
            // HIER den Ballon nach Osten bewegen um den Betrag 'pixelPerFrame'
            break;
        case 'S':
            // HIER den Ballon nach Süden bewegen um den Betrag 'pixelPerFrame'
            break;
        case 'W':
            // HIER den Ballon nach Westen bewegen um den Betrag 'pixelPerFrame'
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
    QFont   f;
    f.setPixelSize(30);
    p->setFont(f);

    /* ***********************************************
     * Zeichnen Sie hier die Kompass Windrose (statisch)
     * **********************************************/

    /* ***********************************************
     * Zeichnen Sie hier den Ballon (an aktueller Position)
     * **********************************************/
}
