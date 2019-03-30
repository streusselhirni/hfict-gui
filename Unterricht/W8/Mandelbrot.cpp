//
// Created by Nicolas Haenni on 2019-03-23.
//

#include <QPainter>
#include "Mandelbrot.h"
#include "Palette.h"

Mandelbrot::Mandelbrot()
{
    this->setMinimumSize(1920, 1080);
}

Mandelbrot::~Mandelbrot() = default;

void Mandelbrot::paintEvent(QPaintEvent* event)
{
    QPainter p(this);
    auto     pal = new Palette(4, this->maxIterations);

    int xSize = this->width();
    int ySize = this->height();

    for (int x = 0; x <= xSize; x++) {
        for (int y = 0; y <= ySize; y++) {
            int iterationCounter = calcMandelbrotPoint(x, y);
            p.setPen(pal->getColor(iterationCounter));
            p.drawPoint(x, y);
        }
    }
};

int Mandelbrot::calcMandelbrotPoint(int x, int y)
{
    // Scale coordinates on x = [-2.5;1], y = [-1;1]
    double x1 = xScaleMin + xScaleDiff / this->width() * x;
    double y1 = yScaleMin + xScaleDiff / this->width() * y;

    // Initialize x0 and y0
    double x0 = 0.0;
    double y0 = 0.0;

    // Initialize iteration counter
    int iterationCount = 0;

    // Loop as long as x0^2 + y0^2 < 4.0
    while (x0 * x0 + y0 * y0 < 4.0 && iterationCount < this->maxIterations) {
        // Calculate according to instruction
        double xTemp = x0 * x0 - y0 * y0 + x1;
        y0 = 2 * x0 * y0 + y1;
        x0 = xTemp;

        iterationCount++;
    }

    return iterationCount;
}
