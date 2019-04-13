#include "BallonfahrtSimulator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BallonfahrtSimulator w;
    w.show();

    return a.exec();
}
