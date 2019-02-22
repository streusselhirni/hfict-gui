//
// Created by Nicolas Haenni on 2019-02-22.
//

#include "MainWidget.h"
#include <QLabel>
#include <QSlider>
#include <QCheckBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QDebug>
#include <random>

MainWidget::MainWidget() {
    this->slider = new QSlider(Qt::Horizontal);
    this->slider->setMinimum(7);
    this->slider->setMaximum(24);
    this->slider->setSingleStep(1);
    this->check1 = new QCheckBox("A...Za...z");
    this->check1->setChecked(true);
    this->check2 = new QCheckBox("0...9");
    this->check3 = new QCheckBox("!@#$%");
    this->input  = new QLineEdit("");
    this->input->setText(this->generatePassword());

    this->setMinimumSize(400, 300);
    this->createLayout();

    QObject::connect(this->slider, SIGNAL(sliderMoved(int)), this, SLOT(calculate(int)));
    QObject::connect(this->check1, SIGNAL(stateChanged(int)), this, SLOT(calculate(int)));
    QObject::connect(this->check2, SIGNAL(stateChanged(int)), this, SLOT(calculate(int)));
    QObject::connect(this->check3, SIGNAL(stateChanged(int)), this, SLOT(calculate(int)));
}

MainWidget::~MainWidget() {

}

void MainWidget::createLayout() {
    auto layout = new QGridLayout();
    layout->addWidget(new QLabel("Passwort Generator"), 0, 0, 1, 2);
    layout->addWidget(slider, 1, 0, 1, 2);
    layout->addWidget(check1, 2, 0, 2, 1);
    layout->addWidget(check2, 3, 0, 3, 1);
    layout->addWidget(check3, 4, 0, 4, 1);
    layout->addWidget(input, 5, 0, 5, 1);

    this->setLayout(layout);
}

void MainWidget::calculate(int value) {
    this->input->setText(this->generatePassword());
}

QString MainWidget::generatePassword() {
    std::random_device              rd;
    std::mt19937_64                 gen(rd());
    std::uniform_int_distribution<> alpha(0, 25);
    std::vector<int>                generators;
    QString                         pw("");

    if (this->check1->isChecked()) {
        generators.push_back(1);
    }
    if (this->check2->isChecked()) {
        generators.push_back(2);
    }
    if (this->check3->isChecked()) {
        generators.push_back(3);
    }

    if (generators.empty()) {
        return QString("Error: No checkbox selected!");
    }

    for (int i = 0; i < this->slider->value(); i++) {
        std::shuffle(generators.begin(), generators.end(), rd);

        int number = alpha(gen);
        if (generators.at(0) == 1) {
            if (this->check1->isChecked()) {
                if (rand() % 2 == 1) number += 'a';
                else number += 'A';
                pw.append(static_cast<char>(number));
            }
        } else if (generators.at(0) == 2) {
            number %= 9;
            pw.append(QString::number(number));
        } else if (generators.at(0) == 3) {
            number %= this->specialChars.size();
            pw.append(this->specialChars.at(number));
        }
    }

    return pw;
}
