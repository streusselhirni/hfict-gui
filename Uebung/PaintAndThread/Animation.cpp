//
// Created by Nicolas Haenni on 2019-04-12.
//
#include <QDebug>
#include "Animation.h"

Animation::Animation() : running(false)
{}

void Animation::run()
{
    while (running) {
        qDebug() << "RUN";
        emit animationEvent();
        msleep(100);
    }
}

void Animation::resume()
{
    this->running = true;
    this->start();
}

void Animation::suspense()
{
    this->running = false;
}