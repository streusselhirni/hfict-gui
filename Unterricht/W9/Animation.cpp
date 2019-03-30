//
// Created by Nicolas Haenni on 2019-03-30.
//

#include "Animation.h"

void Animation::run()
{
    while (running) {
        emit animationEvent(5);
        msleep(static_cast<unsigned long>(this->intervalUs));
    }
}

void Animation::resume()
{
    if (!running) {
        this->running = true;
        this->start();
    }
}

void Animation::suspend()
{
    if (running) this->running = false;
}

Animation::Animation() : running(false), intervalUs(50)
{}

void Animation::setIntervalUs(int speed)
{
    this->intervalUs = speed;
}