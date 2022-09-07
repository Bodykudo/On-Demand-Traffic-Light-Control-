#include "button.h"

// Function used to initialize the button
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin) {
    DIO_init(buttonPort, buttonPin, IN);
}

// Function used to read the value stored in the button
uint8_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin) {
    return DIO_read(buttonPort, buttonPin);
}