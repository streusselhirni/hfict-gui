//
// Created by Nicolas Haenni on 2019-04-06.
//
#include <QDebug>
#include "WorkerThread.h"
#include "MainWidget.h"

WorkerThread::WorkerThread(MainWidget *parent) : loops(0), w(parent)
{}

int WorkerThread::getLoops() const
{
    return this->loops;
}

void WorkerThread::setLoops(int value)
{
    this->loops = value;
}

void WorkerThread::run()
{
    qDebug() << "WorkerThread was called";
    for (int i = 0; i < loops; i++) {
        w->incrementCounter();
    }
}
