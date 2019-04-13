#include <QDebug>
#include "Animation.h"

Animation::Animation() : running(false)
{};

void Animation::run()
{
    while (running) {
        emit animationEvent();
        msleep(40);
    }
}

void Animation::resume()
{
    qDebug() << "Resuming";
    if (!running) {
        running = true;
        this->start();
    }
}

void Animation::suspend()
{
    running = false;
}
