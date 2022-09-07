#include "dio.h"

// Function used to initialize the DIO port direction (IN/OUT)
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction) {
    switch (portNumber) {
        case PORT_A:
            if (direction == IN) {
                CLR_BIT(DDRA, pinNumber);
            } else if (direction == OUT) {
                SET_BIT(DDRA, pinNumber);
            } else {
                // Error
            }
            break;

        case PORT_B:
            if (direction == IN) {
                CLR_BIT(DDRB, pinNumber);
            } else if (direction == OUT) {
                SET_BIT(DDRB, pinNumber);
            } else {
                // Error
            }
            break;

        case PORT_C:
            if (direction == IN) {
                CLR_BIT(DDRC, pinNumber);
            } else if (direction == OUT) {
                SET_BIT(DDRC, pinNumber);
            } else {
                // Error
            }
            break;

        case PORT_D:
            if (direction == IN) {
                CLR_BIT(DDRD, pinNumber);
            } else if (direction == OUT) {
                SET_BIT(DDRD, pinNumber);
            } else {
                // Error
            }
            break;

        default:
            // Error
            break;
    }
}

// Function used to write data to DIO port (LOW/HIGH)
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value) {
    switch (portNumber) {
        case PORT_A:
            if (value == LOW) {
                CLR_BIT(PORTA, pinNumber)
            } else if (value == HIGH) {
                SET_BIT(PORTA, pinNumber);
            } else {
                // Error
            }
            break;

        case PORT_B:
            if (value == LOW) {
                CLR_BIT(PORTB, pinNumber)
            } else if (value == HIGH) {
				SET_BIT(PORTB, pinNumber);
            } else {
                // Error
            }
            break;

        case PORT_C:
            if (value == LOW) {
                CLR_BIT(PORTC, pinNumber)
            } else if (value == HIGH) {
                SET_BIT(PORTC, pinNumber);
            } else {
                // Error
            }
            break;

        case PORT_D:
            if (value == LOW) {
                CLR_BIT(PORTD, pinNumber)
            } else if (value == HIGH) {
                SET_BIT(PORTD, pinNumber);
            } else {
                // Error
            }
            break;

        default:
            // Error
            break;
    }
}

// Function used to toggle the value inside DIO port between LOW & HIGH
void DIO_toggle(uint8_t portNumber, uint8_t pinNumber) {
    switch (portNumber) {
        case PORT_A:
            TOGGLE_BIT(PORTA, pinNumber);
            break;

        case PORT_B:
            TOGGLE_BIT(PORTB, pinNumber);
            break;

        case PORT_C:
            TOGGLE_BIT(PORTC, pinNumber);
            break;

        case PORT_D:
            TOGGLE_BIT(PORTD, pinNumber);
            break;

        default:
            // Error
            break;
    }
}

// Function used to read the value inside the DIO port (LOW/HIGH)
uint8_t DIO_read(uint8_t portNumber, uint8_t pinNumber) {
    uint8_t bit;
    switch (portNumber) {
        case PORT_A:
            bit = READ_BIT(PINA, pinNumber);
            return bit;
            break;

        case PORT_B:
            bit = READ_BIT(PINB, pinNumber);
            return bit;
            break;

        case PORT_C:
            bit = READ_BIT(PINC, pinNumber);
            return bit;
            break;

        case PORT_D:
            bit = READ_BIT(PIND, pinNumber);
            return bit;
            break;

        default:
            // Error
            break;
    }
}