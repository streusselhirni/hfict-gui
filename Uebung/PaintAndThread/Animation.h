//
// Created by Nicolas Haenni on 2019-04-12.
//

#ifndef PAINTANDTHREAD_ANIMATION_H
#define PAINTANDTHREAD_ANIMATION_H


#include <QThread>

class Animation : public QThread
{
Q_OBJECT;

public:
    Animation();

private:
    bool running;
    void run() override;

public slots:
    void resume();
    void suspense();

signals:
    void animationEvent();
};


#endif //PAINTANDTHREAD_ANIMATION_H
