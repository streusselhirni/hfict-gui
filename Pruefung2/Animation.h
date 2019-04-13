//
// Created by Nicolas Haenni on 2019-04-13.
//

#ifndef PRUEFUNG2_ANIMATION_H
#define PRUEFUNG2_ANIMATION_H


#include <QThread>

class Animation : public QThread
{
Q_OBJECT
public:
    Animation();
    void resume();
    void suspend();

private:
    bool running;
    void run() override;

signals:
    void animationEvent();
};


#endif //PRUEFUNG2_ANIMATION_H
