//
// Created by Nicolas Haenni on 2019-04-12.
//

#ifndef PAINTANDTHREAD_PAINTER_H
#define PAINTANDTHREAD_PAINTER_H

#include <QWidget>

class QPoint;

class Painting : public QWidget
{
    Q_OBJECT;

private:
    int x1;
    int x2;
    bool growing;

protected:
    void paintEvent(QPaintEvent *e) override;

public:
    explicit Painting(QWidget* parent);
    ~Painting() override;

public slots:
    void move();
};


#endif //PAINTANDTHREAD_PAINTER_H
