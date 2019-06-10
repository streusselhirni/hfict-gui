#include "Engine.h"
#include <QtMath>
#include <QPainter>

{
    // P1 - Calculate Center Point of the Flywheel
    QPoint p1(static_cast<int>(this->width() * 0.5), static_cast<int>(this->height() * 0.65));

    // P2 - pCalculate Coordinates of the Connection Rod Bearing on the Flywheel
    double rb_x = connectionRodBearingRadius * qCos(angleAlpha);
    double rb_y = connectionRodBearingRadius * qSin(angleAlpha);
    QPoint p2(static_cast<int>(p1.rx() - rb_x), static_cast<int>(p1.ry() + rb_y));

    // P3 - Calculate Position of the Piston Bearing (using Pythagoras)
    double distance_y = sqrt(connectingRodLength * connectingRodLength - rb_x * rb_x);
    QPoint p3(p1.x(), p2.y() - static_cast<int>(distance_y));

    // Setup QPainter
    QPainter p(this);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
    p.setPen(QPen(Qt::black));

    // Draw Flywheel
    p.drawEllipse(p1, flyWheelDiameter, flyWheelDiameter);

    // Draw Connecting Rod
    p.setPen(QPen(Qt::blue, 10));
    p.drawPoint(p2.rx(), p2.ry());
    p.drawPoint(p3.rx(), p3.ry());
    p.setPen(QPen(Qt::blue, 3));
    p.drawLine(p2, p3);

    // Draw Piston
    p.setPen(QPen(Qt::red, 2));
    int    p_w = static_cast<int>(flyWheelDiameter * 0.75);
    QPoint pp1(p3.x() - p_w, static_cast<int>(p3.y() + p_w * 0.5));
    QPoint pp2(pp1.x() + p_w * 2, pp1.y());
    QPoint pp3(pp2.x(), pp2.y() - p_w);
    QPoint pp4(pp3.x() - p_w * 2, pp3.y());
    QPoint pp5(pp4.x(), static_cast<int>(pp4.y() + p_w * 0.2));
    QPoint pp6(pp5.x() + p_w * 2, pp5.y());

    p.drawPoint(pp1);
    p.drawPoint(pp2);
    p.drawPoint(pp3);
    p.drawPoint(pp4);

    p.drawLine(pp1, pp2);
    p.drawLine(pp2, pp3);
    p.drawLine(pp3, pp4);
    p.drawLine(pp4, pp1);
    p.drawLine(pp4, pp5);
    p.drawLine(pp5, pp6);
    p.drawLine(pp6, pp3);
}

void Engine::move(double degrees)
{
    angleAlpha += 2.0 * M_PI / 360.0 * degrees;
    this->repaint();
}

Engine::Engine(QWidget* parent)
{
    this->setParent(parent);
    this->setMinimumSize(300, 400);
    this->setStyleSheet("background-color: #E6E3FF");

    angleAlpha                 = M_PI;
    flyWheelDiameter           = 50;
    connectionRodBearingRadius = 35;
    connectingRodLength        = 170;
}

Engine::~Engine() = default;
