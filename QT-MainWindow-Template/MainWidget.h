#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class MainWidget : public QWidget {
Q_OBJECT

private:

public:
    explicit MainWidget(QWidget* parent = nullptr);
    ~MainWidget() override;
};

#endif // MAINWIDGET_H