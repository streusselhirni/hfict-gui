#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

class QPoint;

class QString;

class QPaintEvent;

class Canvas : public QWidget
{
Q_OBJECT
private:
    int     pixelPerFrame = 10;
    QPoint  * ballon;
    QString direction;

protected:
    void paintEvent(QPaintEvent* e);

public:
    explicit Canvas(QWidget* parent = nullptr);
    ~Canvas();

signals:

public slots:
    void updateDirection(QString s);
    void moveBallon();
};

#endif // CANVAS_H
