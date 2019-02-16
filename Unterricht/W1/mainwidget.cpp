#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QDateTime>
#include <QMessageBox>
#include "mainwidget.h"
#include "Controller.h"
#include "Store.h"

using namespace std;

MainWidget::MainWidget() {
    createLayout();
    setupEventHandling();
}

MainWidget::~MainWidget() = default;

void MainWidget::createLayout() {
    QPixmap icon("creditcards.png");
    QLabel* iconLabel;
    if (icon.isNull()) {
        iconLabel = new QLabel("icon not found!");
    }
    else {
        iconLabel = new QLabel();
        iconLabel->setPixmap(icon.scaledToHeight(100));
    }
    QLabel* titleLabel = new QLabel("<H1 style='color: deeppink'>Credit Card Checker</H1>");

    this->blockInput = new QLineEdit*[4];
    for (int i = 0; i < 4; i++) {
        this->blockInput[i] = new QLineEdit();
        this->blockInput[i]->setPlaceholderText("0000");
        this->blockInput[i]->setMaxLength(4);
        this->blockInput[i]->setValidator(new QIntValidator());
    }

    this->monthBox    = new QComboBox();
    this->yearBox     = new QComboBox();
    this->checkButton = new QPushButton("Check");
    this->clearButton = new QPushButton("Clear");

    this->setDefaultValues();

    // create layout
    auto* layout = new QGridLayout();
    layout->addWidget(titleLabel, 0, 0, 1, 3);
    layout->addWidget(iconLabel, 0, 3);
    for (int i = 0; i < 4; i++) {
        layout->addWidget(this->blockInput[i], 1, i);
    }
    layout->addWidget(new QLabel("Month"), 2, 0);
    layout->addWidget(this->monthBox, 2, 1);
    layout->addWidget(new QLabel("Year"), 2, 2);
    layout->addWidget(this->yearBox, 2, 3);
    layout->addWidget(this->checkButton, 3, 0, 1, 2);
    layout->addWidget(this->clearButton, 3, 2, 1, 2);

    // set layout
    this->setLayout(layout);
}

void MainWidget::setDefaultValues() {
    QString      monthNames[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Okt", "Nov", "Dez"};
    for (const QString& mName : monthNames) {
        monthBox->addItem(mName);
    }

    // for the year, take the current year and add the next 10 years
    QDateTime currentDate     = QDateTime::currentDateTime();
    int       currentYear     = currentDate.date().year();
    const int NUMBER_OF_YEARS = 10;
    for (int  i               = 0; i < NUMBER_OF_YEARS; i++) {
        QString year = QString::number(currentYear + i);
        yearBox->addItem(year);
    }
}

void MainWidget::setupEventHandling() {
    QObject::connect(checkButton, SIGNAL(clicked(bool)), this, SLOT(getData()));
}

void MainWidget::getData() {
    QString number;
    for (int i = 0; i < 4; i++) {
        number.append(QString(blockInput[i]->text()));
    }
    auto cc = new CreditCard();
    cc->setNumber(number);
    cc->setMonth(this->monthBox->currentText());
    cc->setYear(this->yearBox->currentText().toInt());
    // TODO: Create Controller Instance to validate CC
    Store::getInstance()->setCC(cc);
}

void MainWidget::onResultUpdate(CreditCard& cc) {
    qDebug() << "Credit Card Check result is: " << cc.getValidationStatus();
}
