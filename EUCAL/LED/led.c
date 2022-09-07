#include "led.h"

// Function used to initialize the LED
void LED_init(uint8_t ledPort, uint8_t ledPin) {
    DIO_init(ledPort, ledPin, OUT);
}

// Function used to store HIGH value in LED
void LED_on(uint8_t ledPort, uint8_t ledPin) {
    DIO_write(ledPort, ledPin, HIGH);
}

// Function used to store LOW value in LED
void LED_off(uint8_t ledPort, uint8_t ledPin) {
    DIO_write(ledPort, ledPin, LOW);
}

// Function used to toggle the data in LED
void LED_toggle(uint8_t ledPort, uint8_t ledPin) {
    DIO_toggle(ledPort, ledPin);
}