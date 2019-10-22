#include "Racket.h"

/**
 * @brief
 * @note
 * @param
 * @retval
 */
Racket::Racket(int w /*= 20*/, int h /*= 40*/, uint16_t clr /*= TFT_WHITE*/ ) :
    width(w),
    height(h),
    xPos(320),
    yPos(240 / 2),
    yPosOld(240 / 2),
    velocity(4),
    xDir(0),
    yDir(0),
    color(clr)
{ }

/**
 * @brief
 * @note
 * @param
 * @retval
 */
void Racket::home()
{
    xPos = 320;
    yPos = 240 / 2;
    yPosOld = yPos;
    xDir = 0;
    yDir = 0;
}

/**
 * @brief
 * @note
 * @param
 * @retval
 */
void Racket::move(DigitalIn* btnUp, DigitalIn* btnDown)
{
    yDir = 0;
    if (*btnUp == 0)
        yDir = -1;  // move up
    if (*btnDown == 0)
        yDir = 1;   // move down
    yPosOld = yPos;
    yPos += yDir * velocity;
    if (yPos < height / 2)
        yPos = height / 2;
    if (yPos > 240 - height / 2)
        yPos = 240 - height / 2;
}

/**
 * @brief
 * @note
 * @param
 * @retval
 */
void Racket::paint()
{
    if (yDir == 1) {
        tft_boxfill(xPos - width / 2, yPosOld - height / 2, xPos, yPos - height / 2, TFT_BLACK);    // hide racket at old position
        tft_boxfill(xPos - width / 2, yPos - height / 2, xPos, yPos + height / 2, TFT_WHITE);       // draw racket at new position
    }
    else {
        tft_boxfill(xPos - width / 2, yPos + height / 2, xPos, yPosOld + height / 2, TFT_BLACK);    // hide racket at old position
        tft_boxfill(xPos - width / 2, yPos - height / 2, xPos, yPos + height / 2, TFT_WHITE);       // draw racket at new position
    }
}
