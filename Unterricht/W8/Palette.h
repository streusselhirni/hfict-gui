#ifndef PALETTE_H
#define PALETTE_H

class QColor;

class Palette
{

private:
    int   iter;
    int   choice;
    QColor* palette;

public:
    Palette(int c, int it);
    QColor getColor(int i);
    int getChoice();
};

#endif // PALETTE_H
