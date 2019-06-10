#include <QtWidgets>
#include <QVBoxLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QDebug>
#include <QMutex>
#include "MainWidget.h"
#include "WorkerThread.h"

MainWidget::MainWidget(QWidget* parent) : QWidget(parent)
{
    this->counter         = 0;
    this->loopsPerThread  = 500;
    this->amountOfThreads = 5;
    this->mutex           = new QMutex();

    this->lcd = new QLCDNumber();
    this->lcd->setDigitCount(10);
    this->startBtn        = new QPushButton("Start Threads");
    this->reset           = new QPushButton("Reset");
    this->spinBoxQtyLoops = new QSpinBox();
    this->spinBoxQtyLoops->setMaximum(1000000);
    this->spinBoxQtyLoops->setValue(this->loopsPerThread);

    this->spinBoxQtyThreads = new QSpinBox();
    this->spinBoxQtyThreads->setValue(this->amountOfThreads);
    this->spinBoxQtyThreads->setMaximum(1000);
    this->checkBox = new QCheckBox("Enable Mutex");

    this->createLayout();
    this->setupEventHandling();
}

void MainWidget::createLayout()
{
    auto layout = new QGridLayout();

    layout->addWidget(lcd, 0, 0, 1, 6);
    layout->addWidget(new QLabel("Loop Qty"), 1, 0, 1, 2);
    layout->addWidget(startBtn, 1, 2, 1, 2);
    layout->addWidget(spinBoxQtyLoops, 1, 4, 1, 2);
    layout->addWidget(new QLabel("Thread Qty"), 2, 0, 1, 2);
    layout->addWidget(reset, 2, 2, 1, 2);
    layout->addWidget(spinBoxQtyThreads, 2, 4, 1, 2);
    layout->addWidget(checkBox, 3, 0, 1, 1);

    this->setLayout(layout);
}

void MainWidget::setupEventHandling()
{
    connect(reset, &QPushButton::clicked, this, &MainWidget::resetValues);
    connect(startBtn, &QPushButton::clicked, this, &MainWidget::startThreads);
}

void MainWidget::resetValues()
{
    this->counter = 0;
    this->lcd->display(counter);
}

void MainWidget::incrementCounter()
{
    if (this->checkBox->checkState() == Qt::Checked) {
        this->mutex->lock();
        this->counter++;
        this->mutex->unlock();
    } else {
        this->counter++;
    }
}

void MainWidget::startThreads()
{
    this->loopsPerThread  = this->spinBoxQtyLoops->text().toInt();
    this->amountOfThreads = this->spinBoxQtyThreads->text().toInt();

    this->threads = new WorkerThread* [this->amountOfThreads];

    for (int i = 0; i < this->amountOfThreads; i++) {
        qDebug() << "Threads # " << i;
        threads[i] = new WorkerThread(this);
        threads[i]->setLoops(this->loopsPerThread);
    }

    for (int j = 0; j < this->amountOfThreads; j++) {
        threads[j]->start();
    }

    for (int k = 0; k < amountOfThreads; k++) {
        threads[k]->wait();
    }

    this->lcd->display(this->counter);
}

MainWidget::~MainWidget() = default;