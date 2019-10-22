// A simple Pong game with STM32F407VET6 black board (Seeed Arch Max) and ILI9341 320x240 TFT display.
// See more info on the STM32F407VET6 black board at https://os.mbed.com/users/hudakz/code/STM32F407VET6_Hello/
//
#include "mbed.h"
#include "tft.h"
#include "Racket.h"
#include "Ball.h"

// Connect the SPI interface of an ILI9341 320x240 TFT display to the STM32F407VET6 board (Seeed Arch Max) as follows:

// ILI9341                      STM32F407VET6
//   VCC                            +5V
//   GND                            GND
//   CS                             PB_7
//   RESET                          PB_8
//   D/C                            PB_6
//   SDI(MOSI)                      PB_5
//   SCK                            PB_3
//   LED   over a 56 ohm resistor   +5V
//   SDO(MISO)                      PB_4
//
Ticker          ticker;
DigitalIn       racketUp(PE_4, PullUp);     // K0 button
DigitalIn       racketDown(PE_3, PullUp);   // K1 button
Ball            ball;
Racket          racket;
volatile bool   gameOn;
volatile bool   missed;
Timeout         timeout;

/**
 * @brief
 * @note
 * @param
 * @retval
 */
void newGame()
{
    tft_clear(TFT_BLACK);
    racket.home();
    ball.home();
    gameOn = true;
}

/**
 * @brief
 * @note
 * @param
 * @retval
 */
void gameOver()
{
    gameOn = false;
    tft_text(320 / 2 - 35, 240 / 2, "GAME OVER", TFT_WHITE, TFT_BLACK);
    timeout.attach(newGame, 2);
}

/**
 * @brief
 * @note
 * @param
 * @retval
 */
void updateField()
{
    if (gameOn) {
        racket.move(&racketUp, &racketDown);    // move racket
        racket.paint();                         // paint racket
        missed = ball.move(&racket);            // move ball and check for collisions
        if (missed)
            gameOver();
        else
            ball.paint();                       // paint ball
    }
}

DigitalOut  myled(PA_6);   // on-board LED

/**
 * @brief
 * @note
 * @param
 * @retval
 */
int main()
{

    ///*
    tft_init();
    newGame();
    ticker.attach_us(updateField, 20 * 1000);   // update period = 20 ms
    //*/
    while (true) {
        myled = 0;      // turn the LED on
        wait_ms(200);   // wait 200 millisecond
        myled = 1;      // turn the LED off
        //pc.printf("Blink\r\n");
        wait_ms(1000);  // wait 1000 millisecond
    }
}
