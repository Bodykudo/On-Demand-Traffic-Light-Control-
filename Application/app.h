#ifndef APP
#define APP

// States enumeration
enum States {
    GREEN,
    YELLOW_TO_RED,
    RED,
    YELLOW_TO_GREEN
};

// Including libraries
#include "../MCAL/Timer/timer.h"
#include "../MCAL/Interrupt/interrupt.h"
#include "../EUCAL/LED/led.h"
#include "../EUCAL/Button/button.h"

// Defining functions like macros
#define onCarRed() LED_on(PORT_A, 2);
#define onCarGreen() LED_on(PORT_A, 0);
#define offCarRed() LED_off(PORT_A, 2);
#define offCarYellow() LED_off(PORT_A, 1);
#define offCarGreen() LED_off(PORT_A, 0);

#define onPedRed() LED_on(PORT_B, 2);
#define onPedGreen() LED_on(PORT_B, 0);
#define offPedRed() LED_off(PORT_B, 2);
#define offPedYellow() LED_off(PORT_B, 1);
#define offPedGreen() LED_off(PORT_B, 0);

// App functions prototypes
void App_init();
void App_normalMode();

#endif