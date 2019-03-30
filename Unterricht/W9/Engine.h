#ifndef ENGINE_H
#define ENGINE_H

#include <QWidget>

class Engine : public QWidget
{
    Q_OBJECT

private:
    double angleAlpha;
    int flyWheelDiameter;
    int connectionRodBearingRadius;
    int connectingRodLength;

protected:
    void paintEvent(QPaintEvent *e) override;

public slots:
    void move(double degrees);

public:
    explicit Engine(QWidget *parent = nullptr);
    ~Engine() override;

};

#endif // ENGINE_H
