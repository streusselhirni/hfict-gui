#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class QComboBox;

class QLabel;

class QPixmap;

class MainWidget : public QWidget {
Q_OBJECT

private:
    QComboBox* comboBox;
    QLabel   * lbl;
    QPixmap  * image;

    double percentage;

    void activateImage();

public:
    explicit MainWidget(QWidget* parent = nullptr);
    ~MainWidget() override;
    QPixmap getScaledImage(double percent);

public slots:
    void load();
    void percentageChanged(QString);
};

#endif // MAINWIDGET_H