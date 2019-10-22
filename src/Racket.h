#ifndef RACKET_H
#define RACKET_H

#include "mbed.h"
#include "tft.h"

class   Racket
{
public:
    Racket(int w = 20, int h = 40, uint16_t clr = TFT_WHITE);
    void        home();
    void        move(DigitalIn* btnUp, DigitalIn* btnDown);
    void        paint();

    int         width;
    int         height;
    int         xPos;
    int         yPos;
    int         yPosOld;
    float       velocity;
    int         xDir;
    int         yDir;
    bool        moved;
    uint16_t    color;
};
#endif // RACKET_H
