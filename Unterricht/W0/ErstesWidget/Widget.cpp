//
// Created by Nicolas Haenni on 2019-01-19.
//
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include "Widget.h"

Widget::Widget() {
    this->cb1       = new QCheckBox("Option 1");
    this->cb2       = new QCheckBox("Option 2");
    this->cb3       = new QCheckBox("Option 3");
    this->cancelBtn = new QPushButton("Cancel");
    this->okBtn     = new QPushButton("OK");

    auto* grid = new QGridLayout();
    grid->addWidget(new QLabel("<h1 style=\"color: deeppink\">Nick is the best</h1>"), 0, 0, 1, 4);
    grid->addWidget(cb1, 1, 0, 1, 2);
    grid->addWidget(cb2, 2, 0, 1, 2);
    grid->addWidget(cb3, 3, 0, 1, 2);
    grid->addWidget(okBtn, 4, 0, 1, 2);
    grid->addWidget(cancelBtn, 4, 2, 1, 2);

    this->setLayout(grid);
    this->setMinimumSize(400, 200);

    /* auto* lmgr = new QVBoxLayout();
    lmgr->addWidget(new QLabel("<h1 style=\"color: deeppink\">Nick is the best</h1>"));
    lmgr->addWidget(cb1);
    lmgr->addWidget(cb2);
    lmgr->addWidget(cb3);

    auto *edit = new QTextEdit();
    lmgr->addWidget((edit));

    auto* hbox = new QHBoxLayout();
    hbox->addWidget(cancelBtn);
    hbox->addWidget(okBtn);
    lmgr->addLayout(hbox);
    setLayout(lmgr); */

    this->setWindowTitle(QString("HAMMER"));
}

Widget::~Widget() {
    delete this->cb1;
    delete this->cb2;
    delete this->cb3;
    delete this->cancelBtn;
    delete this->okBtn;
}
