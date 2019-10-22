#ifndef BALL_H
#define BALL_H

#include "mbed.h"
#include "tft.h"

class Racket;

class Ball
{
    int         size;
    float       velocity;
    uint16_t    color;
public:
    Ball(int s = 8, float v = 4, uint16_t clr = TFT_WHITE );
    void   home();
    bool   move(Racket* rkt);
    void   paint();
    void   vec2_norm(float& x, float &y);
    
    int    xPos;
    int    yPos;
    int    xPosOld;
    int    yPosOld;
    float  xDir;
    float  yDir;
    
};
#endif // BALL_H
