#include "MainWindow.h"
#include "Painting.h"
#include "Animation.h"
#include <QWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QDebug>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    this->setWindowTitle("PaintAndThead");
    this->setupLayout();
    this->setupThread();
    this->setupEvents();
}

void MainWindow::setupLayout()
{
    this->w        = new QWidget();
    this->startBtn = new QPushButton("Start");
    this->animBtn  = new QPushButton("Animate");
    this->p        = new Painting(this);

    this->animBtn->setCheckable(true);

    auto* vl = new QVBoxLayout();
    vl->addWidget(new QLabel("Eine Übung"));
    vl->addWidget(startBtn);
    vl->addWidget(animBtn);
    vl->addWidget(p);


    w->setLayout(vl);
    this->setCentralWidget(w);
}

void MainWindow::setupEvents()
{
    connect(startBtn, &QPushButton::clicked, p, &Painting::move);
    connect(animBtn, &QPushButton::clicked, this, &MainWindow::animate);
    connect(a, &Animation::animationEvent, p, &Painting::move);
}

void MainWindow::setupThread()
{
    this->a = new Animation();
}

void MainWindow::animate()
{
    qDebug() << "Start animation";
    if (animBtn->isChecked()) {
        a->resume();
    } else {
        a->suspense();
    }
}

MainWindow::~MainWindow() = default;