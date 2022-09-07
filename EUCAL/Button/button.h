#ifndef BUTTON
#define BUTTON

// Including libraries
#include "../../MCAL/DIO/dio.h"

// Driver functions prototypes
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);
uint8_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin);

#endif