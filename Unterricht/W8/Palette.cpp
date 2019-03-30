#include "palette.h"
#include <QColor>

Palette::Palette(int c, int it)
{
    iter    = it;
    palette = new QColor[iter + 1];
    choice  = c;

    switch (c) {
        case (0):
            for (int i = 1; i < iter; i++) {
                palette[i] = QColor(i % 256, i % 256, i % 256);
            }
            break;
            //Fire Red 32k
        case (1):
            for (int i = 0; i < iter / 6; i++)
                palette[i] = QColor((i * 2) % 256, 0, 0);
            for (int i     = (iter / 6) + 1; i < 2 * (iter / 6); i++)
                palette[i] = QColor((i * 2) % 256, (i ^ 2) % 256, 0);
            for (int i     = 2 * (iter / 6) + 1; i < 3 * (iter / 6); i++)
                palette[i] = QColor(0, (i ^ 2) % 256, 0);
            for (int i     = 3 * (iter / 6) + 1; i < 4 * (iter / 6); i++)
                palette[i] = QColor(0, (i ^ 2) % 256, (i ^ 4) % 256);
            for (int i     = 4 * (iter / 6) + 1; i < 5 * (iter / 6); i++)
                palette[i] = QColor(0, 0, (i ^ 4) % 256);
            for (int i     = 5 * (iter / 6) + 1; i < 6 * (iter / 6); i++)
                palette[i] = QColor((i * 2) % 256, 0, (i ^ 4) % 256);
            break;
            //Random
        default:
            /*
            case(2):
                Random random = new Random();
                for (int i=1; i<iter; i++)
                {
                    palette[i]=QColor(random.nextInt(256),random.nextInt(256),random.nextInt(256));
                }
                break;
            */
            //Emerald Green
        case (3):
            for (int i = 1; i < iter; i++) {
                palette[i] = QColor((i) % 256, (i + 60) % 256, (i + 5) % 256);
            }
            break;
            //Bluebomb 32k
        case (4):
            for (int i = 0; i < iter / 6; i++)
                palette[i] = QColor(0, 0, (i * 2) % 256);
            for (int i     = (iter / 6) + 1; i < 2 * (iter / 6); i++)
                palette[i] = QColor(0, (i ^ 2) % 256, (i * 2) % 256);
            for (int i     = 2 * (iter / 6) + 1; i < 3 * (iter / 6); i++)
                palette[i] = QColor(0, (i ^ 2) % 256, 0);
            for (int i     = 3 * (iter / 6) + 1; i < 4 * (iter / 6); i++)
                palette[i] = QColor((i ^ 4) % 256, (i ^ 2) % 256, 0);
            for (int i     = 4 * (iter / 6) + 1; i < 5 * (iter / 6); i++)
                palette[i] = QColor((i ^ 4) % 256, 0, 0);
            for (int i     = 5 * (iter / 6) + 1; i < 6 * (iter / 6); i++)
                palette[i] = QColor((i ^ 4) % 256, 0, (i * 2) % 256);
            break;
            //Lichen 256
        case (5):
            for (int i = 0; i < iter / 6; i++)
                palette[i] = QColor((i * 2) % 256, 0, 0);
            for (int i     = (iter / 6) + 1; i < 2 * (iter / 6); i++)
                palette[i] = QColor((i * 2) % 256, (i ^ 2) % 256, 0);
            for (int i     = 2 * (iter / 6) + 1; i < 3 * (iter / 6); i++)
                palette[i] = QColor(0, (i ^ 2) % 256, 0);
            for (int i     = 3 * (iter / 6) + 1; i < 4 * (iter / 6); i++)
                palette[i] = QColor(0, (i ^ 2) % 256, (i ^ 4) % 256);
            for (int i     = 4 * (iter / 6) + 1; i < 5 * (iter / 6); i++)
                palette[i] = QColor(0, 0, (i ^ 4) % 256);
            for (int i     = 5 * (iter / 6) + 1; i < 6 * (iter / 6); i++)
                palette[i] = QColor((i * 2) % 256, 0, (i ^ 4) % 256);
            break;
            //Redwood 32k
        case (6):
            for (int i = 0; i < iter / 6; i++)
                palette[i] = QColor((i * 4) % 256, 0, 0);
            for (int i     = (iter / 6) + 1; i < 2 * (iter / 6); i++)
                palette[i] = QColor((i * 4) % 256, 0, (i ^ 2) % 256);
            for (int i     = 2 * (iter / 6) + 1; i < 3 * (iter / 6); i++)
                palette[i] = QColor(0, 0, (i ^ 2) % 256);
            for (int i     = 3 * (iter / 6) + 1; i < 4 * (iter / 6); i++)
                palette[i] = QColor(0, (i ^ 4) % 256, (i ^ 2) % 256);
            for (int i     = 4 * (iter / 6) + 1; i < 5 * (iter / 6); i++)
                palette[i] = QColor(0, (i ^ 4) % 256, 0);
            for (int i     = 5 * (iter / 6) + 1; i < 6 * (iter / 6); i++)
                palette[i] = QColor((i * 2) % 256, (i ^ 4) % 256, 0);
            break;
            //Cool Blue.
        case (7):
            for (int i = 0; i < iter; i++)
                palette[i] = QColor((10 + i) % 256, (50 + i) % 256, (150 + 2 * i) % 256);
            break;
            //Dark Side of the Moon!
        case (8):
            for (int i = 0; i < iter / 8; i++)
                palette[i] = QColor(0, 0, 0);
            for (int i     = (iter / 7) + 1; i < 2 * (iter / 7); i++)
                palette[i] = QColor(234, 64, 89);
            for (int i     = 2 * (iter / 7) + 1; i < 3 * (iter / 7); i++)
                palette[i] = QColor(235, 159, 67);
            for (int i     = 3 * (iter / 7) + 1; i < 4 * (iter / 7); i++)
                palette[i] = QColor(250, 220, 52);
            for (int i     = 4 * (iter / 7) + 1; i < 5 * (iter / 7); i++)
                palette[i] = QColor(138, 182, 78);
            for (int i     = 5 * (iter / 7) + 1; i < 6 * (iter / 7); i++)
                palette[i] = QColor(104, 162, 230);
            for (int i     = 6 * (iter / 7) + 1; i < 7 * (iter / 7); i++)
                palette[i] = QColor(136, 118, 134);
            break;
    }
}

QColor Palette::getColor(int i)
{
    return palette[i];
}

int Palette::getChoice()
{
    return choice;
}

