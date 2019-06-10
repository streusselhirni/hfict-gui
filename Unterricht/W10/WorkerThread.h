//
// Created by Nicolas Haenni on 2019-04-06.
//

#ifndef WOCHE9_WORKERTHREAD_H
#define WOCHE9_WORKERTHREAD_H


#include <QThread>

class MainWidget;

class WorkerThread : public QThread
{
private:
    int loops;
    MainWidget* w;

public:
    explicit WorkerThread(MainWidget *parent);
    int getLoops() const;
    void setLoops(int value);
    void run() override;
};


#endif //WOCHE9_WORKERTHREAD_H
