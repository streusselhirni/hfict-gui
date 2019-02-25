#include "MainWidget.h"
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QFileDialog>

MainWidget::MainWidget(QWidget* parent) : QWidget(parent), percentage(1) {
    this->comboBox = new QComboBox();
    this->comboBox->addItem("50%");
    this->comboBox->addItem("100%");
    this->comboBox->addItem("200%");
    this->comboBox->setCurrentIndex(1);

    this->lbl   = new QLabel("");
    this->lbl->setAlignment(Qt::AlignCenter);
    this->image = new QPixmap();

    auto layout = new QGridLayout();
    layout->addWidget(this->comboBox, 0, 0);
    layout->addWidget(lbl, 1, 0);
    this->setLayout(layout);

    QObject::connect(this->comboBox, SIGNAL(activated(QString)), this, SLOT(percentageChanged(QString)));
}

MainWidget::~MainWidget() = default;

QPixmap MainWidget::getScaledImage(double percent) {
    int newHeight = static_cast<int>(this->image->height() * percent);
    return this->image->scaledToHeight(newHeight);
}

void MainWidget::activateImage() {
    this->lbl->setPixmap(this->getScaledImage(this->percentage));
}

void MainWidget::load() {
    // This line wil open the file dialogue in my personal stock photos directory.
    QDir path("/Users/nicolashaenni/Pictures/Stock Photos");
    // If the directory doesn't exists (which will be the case), set the path to an empty string
    // so the file dialogue opens in the program's current working directory.
    if (!path.exists()) path.setPath("");
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), path.path());

    this->image = new QPixmap(fileName);
    if (!this->image->isNull()) this->activateImage();
}

void MainWidget::percentageChanged(QString text) {
    if (text == "50%") {
        this->percentage = 0.5;
    } else if (text == "100%") {
        this->percentage = 1;
    } else {
        this->percentage = 2;
    }

    if (!this->image->isNull()) this->activateImage();
}
