#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDebug>

#include "mainwidget.h"
#include "Controller.h"
#include "Store.h"

using namespace std;

MainWidget::MainWidget() {
    auto* title = new QLabel("TITLE");
    this->button = new QPushButton("ok");
    this->input = new QLineEdit();

    auto* layout = new QVBoxLayout();
    layout->addWidget(title);
    layout->addWidget(input);
    layout->addWidget(button);

    this->setLayout(layout);

    auto* controller = new Controller();

    QObject::connect(button, SIGNAL(clicked(bool)), controller, SLOT(onButtonClicked()));

    QString str("SUPER");
    Store::getInstance()->setText(str);
}


MainWidget::~MainWidget() = default;
