//
// Created by Nicolas Haenni on 2019-03-23.
//

#ifndef WOCHE8_MAINWIDGET_H
#define WOCHE8_MAINWIDGET_H


#include <QWidget>

class Palette;

class Mandelbrot : public QWidget
{
Q_OBJECT
public:
    Mandelbrot();
    ~Mandelbrot() override;
protected:
    int calcMandelbrotPoint(int x, int y);
    void paintEvent(QPaintEvent*) override;
private:
    double xScaleMin  = -2.5;
    double xScaleMax  = 1.0;
    double yScaleMin  = -1.0;
    double yScaleMax  = 1.0;
    double xScaleDiff = xScaleMax - xScaleMin;
    double yScaleDiff = yScaleMax - yScaleMin;

    int maxIterations = 100;
};


#endif //WOCHE8_MAINWIDGET_H
