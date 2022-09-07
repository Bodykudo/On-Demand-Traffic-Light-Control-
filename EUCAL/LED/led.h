#ifndef LED
#define LED

// Including libraries
#include "../../MCAL/DIO/dio.h"

// Driver functions prototypes
void LED_init(uint8_t ledPort, uint8_t ledPin);
void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_toggle(uint8_t ledPort, uint8_t ledPin);

#endif