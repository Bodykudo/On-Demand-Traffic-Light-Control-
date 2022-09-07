#ifndef DIO
#define DIO

// Including libraries
#include "../../utils/types.h"
#include "../../utils/bitMaths.h"
#include "../../utils/registers.h"

// Driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

// Direction defines
#define IN 0
#define OUT 1

// Value defines
#define LOW 0
#define HIGH 1

// Driver functions prototypes
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction); // Initialize DIO direction
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value); // Write data to DIO
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber); // Toggle DIO data
uint8_t DIO_read(uint8_t portNumber, uint8_t pinNumber); // Read DIO data

#endif