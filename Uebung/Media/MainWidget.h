//
// Created by Nicolas Haenni on 2019-02-22.
//

#ifndef MEDIATEST_MAINWIDGET_H
#define MEDIATEST_MAINWIDGET_H

#include <QWidget>

class QString;
class QPushButton;
class QMediaPlayer;
class QLabel;
class QPixmap;

class MainWidget : public QWidget {
    Q_OBJECT;

private:
    QPushButton *playBtn;
    QMediaPlayer *player;
    QPixmap *icon;
    QLabel *imgLbl;
    QString fileName;
    bool playing;

public:
    MainWidget();
    ~MainWidget();

public slots:
    void openFile(bool);
    void playFile(bool);

signals:
    void fileSelected(QString);

};


#endif //MEDIATEST_MAINWIDGET_H
