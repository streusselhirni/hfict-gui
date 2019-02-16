//
// Created by Nicolas Haenni on 2019-01-19.
//
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QDebug>
#include <QIntValidator>
#include "Widget.h"

Widget::Widget() {
    this->le1 = new QLineEdit(); // Allow only numbers and 4 characters
    this->le2 = new QLineEdit(); // Allow only numbers and 4 characters
    this->le3 = new QLineEdit(); // Allow only numbers and 4 characters
    this->le4 = new QLineEdit(); // Allow only numbers and 4 characters
    le1->setPlaceholderText("XXXX");
    le2->setPlaceholderText("XXXX");
    le3->setPlaceholderText("XXXX");
    le4->setPlaceholderText("XXXX");
    le1->setMaxLength(4);
    le2->setMaxLength(4);
    le3->setMaxLength(4);
    le4->setMaxLength(4);
    auto iv = new QIntValidator();
    iv->setRange(0, 9999);
    le1->setValidator(iv);
    le2->setValidator(iv);
    le3->setValidator(iv);
    le4->setValidator(iv);
    this->checkBtn = new QPushButton("Check");
    checkBtn->setToolTip("Klicken zum checken");
    this->clearBtn = new QPushButton("Clear");
    clearBtn->setToolTip("Klicken um Felder zu leeren");
    this->answerLbl = new QLabel("Kreditkartennummer eingeben und Check drücken");

    QPixmap pm(200, 100);
    pm.load("mcvisa.png");
    auto imgLbl = new QLabel();
    imgLbl->setPixmap(pm.scaled(50, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    auto* hbox1 = new QHBoxLayout();
    hbox1->addWidget(new QLabel("<h1 style=\"font-size: 30px;\">Kreditkarten Check</h1>"), 2, Qt::AlignLeft);
    hbox1->addWidget(imgLbl, 0, Qt::AlignRight);

    auto* hbox2 = new QHBoxLayout();
    hbox2->addWidget(new QLabel("Nr.:"));
    hbox2->addWidget(le1);
    hbox2->addWidget(new QLabel("-"));
    hbox2->addWidget(le2);
    hbox2->addWidget(new QLabel("-"));
    hbox2->addWidget(le3);
    hbox2->addWidget(new QLabel("-"));
    hbox2->addWidget(le4);

    auto* hbox3 = new QHBoxLayout();
    hbox3->addWidget(checkBtn);
    hbox3->addWidget(clearBtn);

    auto* hbox4 = new QHBoxLayout();
    hbox4->addWidget(answerLbl, 1, Qt::AlignCenter);

    auto* vbox = new QVBoxLayout();
    vbox->addLayout(hbox1);
    vbox->addSpacerItem(new QSpacerItem(600, 20));
    vbox->addLayout(hbox2);
    vbox->addSpacerItem(new QSpacerItem(600, 20));
    vbox->addLayout(hbox4);
    vbox->addLayout(hbox3);

    this->setLayout(vbox);
    this->setFixedSize(600, 300);

    // TODO: Add function to validate
    // TODO: Make result of validation green/red without CSS
//    QObject::connect(checkBtn, &QAbstractButton::clicked, &Widget::check);
}

Widget::~Widget() {
    delete le1;
    delete le2;
    delete le3;
    delete le4;
    delete checkBtn;
}