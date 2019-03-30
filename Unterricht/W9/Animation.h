//
// Created by Nicolas Haenni on 2019-03-30.
//

#ifndef ANIMATEDENGINE_ANIMATION_H
#define ANIMATEDENGINE_ANIMATION_H


#include <QThread>

class Animation : public QThread
{
Q_OBJECT

public:
    Animation();

private:
    bool running;
    int  intervalUs;
    void run() override;

public slots:
    void setIntervalUs(int);
    void resume();
    void suspend();

signals:
    void animationEvent(double degrees);
};


#endif //ANIMATEDENGINE_ANIMATION_H
