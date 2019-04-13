#include <QDebug>
#include <QLabel>
#include <QGridLayout>
#include <QComboBox>
#include <QPushButton>
#include "BallonfahrtSimulator.h"
#include "canvas.h"

void BallonfahrtSimulator::setupLayout()
{
    QGridLayout *gl = new QGridLayout();

    canvas = new Canvas(this);
    gl->addWidget(canvas, 0, 0, 1, 4);

    QLabel *cbbLabel = new QLabel(this);
    cbbLabel->setText("Flugrichtung:");
    gl->addWidget(cbbLabel, 1, 0);

    cbb = new QComboBox(this);
    cbb->addItem("Norden");
    cbb->addItem("Osten");
    cbb->addItem("Süden");
    cbb->addItem("Westen");
    cbb->addItem("Position Halten");
    gl->addWidget(cbb, 1, 1);

    btnNextFrame = new QPushButton(this);
    btnNextFrame->setText("Nächstes Frame");
    gl->addWidget(btnNextFrame, 1, 2);

    btnStartAnimation = new QPushButton(this);
    btnStartAnimation->setText("Starte Animation");
    btnStartAnimation->setCheckable(true);
    gl->addWidget(btnStartAnimation, 1, 3);

    this->setLayout(gl);
}

void BallonfahrtSimulator::setupEvents()
{
    connect(cbb, SIGNAL(currentTextChanged(QString)),
            canvas, SLOT(updateDirection(QString)));

    connect(btnStartAnimation, SIGNAL(toggled(bool)),
            this, SLOT(buttonToggled()));
}

void BallonfahrtSimulator::buttonToggled()
{
    if (btnStartAnimation->isChecked())
    {
        btnStartAnimation->setText("Stoppe Animation");
        qDebug() << "Resume Animation";
    }
    else
    {
        btnStartAnimation->setText("Starte Animation");
        qDebug() << "Suspend Animation";
    }
}

BallonfahrtSimulator::BallonfahrtSimulator(QWidget *parent)
        : QWidget(parent)
{
    setupLayout();
    setupEvents();
}

BallonfahrtSimulator::~BallonfahrtSimulator()
{

}
