#ifndef BALLONFAHRTSIMULATOR_H
#define BALLONFAHRTSIMULATOR_H

#include <QWidget>

class Canvas;

class QComboBox;

class QPushButton;

class Animation;

class BallonfahrtSimulator : public QWidget
{
Q_OBJECT

private:
    Canvas     * canvas;
    QComboBox  * cbb;
    QPushButton* btnNextFrame;
    QPushButton* btnStartAnimation;
    Animation  * animation;

public:
    void setupLayout();
    void setupEvents();
    BallonfahrtSimulator(QWidget* parent = 0);
    ~BallonfahrtSimulator();

private slots:
    void buttonToggled();
};

#endif // BALLONFAHRTSIMULATOR_H
