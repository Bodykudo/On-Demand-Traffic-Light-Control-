#include "timer.h"

void Timer_t0_init() {
    // Set timer t0 mode to normal mode
    TCCR0 = 0x00;

    // Set timer t0 initial value to 0
    TCNT0 = 0;
}

void Timer_t0_delay(float mSeconds) {
    uint32_t overFlowCounter = 0;

    // Initialize timer t0
    Timer_t0_init();

    while (overFlowCounter < (mSeconds * 500 / 256.0)) {
        // Stop after one overflow
        while ((TIFR ^= (1 << 0)) == 0);

        // Clear the overflow flag
        SET_BIT(TIFR, 0);
        overFlowCounter++;
    }
    // Stop timer
    TCCR0 = 0x00;
}

void Timer_t2_init() {
    // Set timer t0 mode to normal mode
    TCCR2 = 0x00;

    // Set timer t0 initial value to 0
    TCNT2 = 0;
}

void Timer_t2_delay(float mSeconds) {
    uint32_t overFlowCounter = 0;

    // Initialize timer t2
    Timer_t2_init();

    while (overFlowCounter < (mSeconds * 500 / 256.0)) {
        // Stop after one overflow
        while ((TIFR ^= (1 << 6)) == 0);

        // Clear the overflow flag
        SET_BIT(TIFR, 6);
        overFlowCounter++;
    }
    // Stop timer
    TCCR2 = 0x00;
}