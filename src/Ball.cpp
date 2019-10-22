#include "Ball.h"
#include "Racket.h"

/**
 * @brief
 * @note
 * @param
 * @retval
 */
Ball::Ball(int s /*= 8*/, float v /*= 8*/, uint16_t clr /*= TFT_WHITE*/ ) :
    size(s),
    velocity(v),
    color(clr),
    xPos(320 / 2),
    yPos(240 / 2),
    xPosOld(320 / 2),
    yPosOld(240 / 2),
    xDir(-1),
    yDir(1)
{ }

/**
 * @brief
 * @note
 * @param
 * @retval
 */
void Ball::home()
{
    xPos = 320 / 2;
    yPos = 240 / 2;
    xPosOld = xPos;
    yPosOld = yPos;
    xDir = -1;
    yDir = 1;
}

/**
 * @brief
 * @note
 * @param
 * @retval
 */
bool Ball::move(Racket* rkt)
{
    xPosOld = xPos;
    yPosOld = yPos;
    xPos += xDir * velocity;
    yPos += yDir * velocity;

    // hit by racket?
    if
    (
        rkt->xPos - rkt->width / 2 < xPos + size / 2 &&
        xPos + size / 2 < rkt->xPos &&
        rkt->yPos - rkt->height / 2 < yPos + size / 2 &&
        yPos - size / 2 < rkt->yPos + rkt->height / 2
    ) {
        xPos = rkt->xPos - rkt->width / 2 - size / 2;
        xDir = -fabs(xDir); // force it to be negative
    }

    // missed racket?
    if (xPos > 320) {
        xPos = 320 / 2;
        yPos = 240 / 2;
        xDir = -1;
        yDir = 1;
        return true;
    }

    // hit left wall?
    if (xPos - size / 2 < 0) {
        xPos = size / 2;
        xDir = fabs(xDir);  // force it to be positive
    }

    // hit bottom wall?
    if (yPos + size / 2 > 240) {
        yPos = 240 - size / 2;
        yDir = -fabs(yDir); // force it to be negative
    }

    // hit top wall?
    if (yPos - size / 2 < 0) {
        yPos = size / 2;
        yDir = fabs(yDir);  // force it to be positive
    }

    // make sure that length of dir stays at 1
    vec2_norm(xDir, yDir);

    return false;
}

/**
 * @brief
 * @note
 * @param
 * @retval
 */
void Ball::paint()
{
    tft_boxfill(xPosOld - size / 2, yPosOld - size / 2, xPosOld + size / 2, yPosOld + size / 2, TFT_BLACK); // hide ball at old position
    tft_boxfill(xPos - size / 2, yPos - size / 2, xPos + size / 2, yPos + size / 2, TFT_WHITE); // draw ball at new position
}

/**
 * @brief
 * @note
 * @param
 * @retval
 */
void Ball::vec2_norm(float& x, float& y)
{
    // sets vector's length to 1 (which means that x + y = 1)
    float   length = sqrt((x * x) + (y * y));
    if (length != 0.0f) {
        length = 1.0f / length;
        x *= length;
        y *= length;
    }
}
