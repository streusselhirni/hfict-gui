//
// Created by Nicolas Haenni on 2019-02-22.
//

#include "MainWidget.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QDebug>

MainWidget::MainWidget() : playing(false) {
    this->playBtn = new QPushButton("Play");
    this->icon = new QPixmap("/Users/nicolashaenni/Education/HF-ICT/GUI/Uebung/Media/stop.jpg");

    auto openBtn = new QPushButton("Open");
    this->imgLbl = new QLabel("");
    imgLbl->setPixmap(icon->scaledToHeight(50));

    auto layout = new QGridLayout();
    layout->addWidget(new QLabel("<h1>Media-Tester</h1>"), 0, 0);
    layout->addWidget(imgLbl, 0, 1);
    layout->addWidget(openBtn, 1, 0, 1, 0);
    layout->addWidget(playBtn, 2, 0, 1, 0);
    this->setLayout(layout);

    this->player = new QMediaPlayer();

    QObject::connect(openBtn, SIGNAL(clicked(bool)), this, SLOT(openFile(bool)));
    QObject::connect(playBtn, &QPushButton::clicked, this, &MainWidget::playFile);
}

MainWidget::~MainWidget() {

}

void MainWidget::openFile(bool) {
    this->fileName = QFileDialog::getOpenFileName(this);
    emit(fileSelected(this->fileName));
}

void MainWidget::playFile(bool) {
    if (this->fileName.isEmpty()) {
        qDebug() << "No file selected";
        return;
    }
    if (!this->playing) {
        qDebug() << "Start playing";
        this->player->setMedia(QUrl::fromLocalFile(this->fileName));
        this->player->setVolume(100);
        this->player->play();
        this->playing = true;
        this->playBtn->setText("Stop");
        delete this->icon;
        this->icon = new QPixmap("/Users/nicolashaenni/Education/HF-ICT/GUI/Uebung/Media/play.png");
        this->imgLbl->setPixmap(icon->scaledToHeight(50));
    } else {
        this->player->stop();
        this->playing = false;
        this->playBtn->setText("Start");
        delete this->icon;
        this->icon = new QPixmap("/Users/nicolashaenni/Education/HF-ICT/GUI/Uebung/Media/stop.jpg");
        this->imgLbl->setPixmap(icon->scaledToHeight(50));
    }
}
