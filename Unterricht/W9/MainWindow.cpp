#include "MainWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QPushButton>
#include "Engine.h"
#include "Animation.h"

void MainWindow::setupLayout()
{
    auto *cw = new QWidget();
    auto *bl = new QHBoxLayout();
    auto *vl = new QVBoxLayout();

    slider = new QSlider();
    slider->setRange(2, 100);
    slider->setTickInterval(2);
    slider->setInvertedAppearance(true);
    slider->setTickPosition(QSlider::TicksBothSides);

    buttonAnimationSwitch = new QPushButton();
    buttonAnimationSwitch->setCheckable(true);
    buttonAnimationSwitch->setGeometry(0,0,20,40);
    buttonAnimationSwitch->setText("ON");

    buttonAnimationStepper = new QPushButton();
    buttonAnimationStepper->setGeometry(0,0,20,40);
    buttonAnimationStepper->setText("Turn Engine");

    vl->addWidget(slider);
    vl->setAlignment(slider, Qt::AlignHCenter);
    vl->addWidget(buttonAnimationSwitch);
    vl->addWidget(buttonAnimationStepper);

    engine = new Engine(this);

    bl->addWidget(engine);
    bl->addLayout(vl);

    cw->setLayout(bl);

    this->setCentralWidget(cw);
}

void MainWindow::setupSignalProviderThread()
{
    this->animation = new Animation();
}

void MainWindow::setupConnections()
{
    connect(buttonAnimationSwitch, &QPushButton::clicked, this, &MainWindow::buttonToggled);
    connect(buttonAnimationStepper, &QPushButton::pressed,this, &MainWindow::buttonAnimationStepperClicked);
    connect(slider, &QSlider::valueChanged, animation, &Animation::setIntervalUs);
    connect(animation, &Animation::animationEvent, engine, &Engine::move);
}

void MainWindow::buttonToggled()
{
    if (buttonAnimationSwitch->isChecked())
    {
        buttonAnimationSwitch->setText("OFF");
        this->animation->resume();
    }
    else
    {
        buttonAnimationSwitch->setText("ON");
        this->animation->suspend();
    }
}

void MainWindow::buttonAnimationStepperClicked()
{
    engine->move(5);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupLayout();
    setupSignalProviderThread();
    setupConnections();
    slider->setValue(5000);
}

MainWindow::~MainWindow()
{
    delete buttonAnimationSwitch;
    delete buttonAnimationStepper;
    delete slider;
    delete engine;
    delete animation;
}
