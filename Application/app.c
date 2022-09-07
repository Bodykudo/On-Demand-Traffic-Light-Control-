#include "app.h"

uint8_t state;

// Helper function used to blink cars yellow LED
void blinkCarYellow() {
    for (uint8_t i = 0; i < 10; i++) {
        LED_toggle(PORT_A, 1);
        Timer_t0_delay(500);
    }
    LED_off(PORT_A, 1);
}

// Helper function used to blink pedestrians yellow LED
void blinkPedestrianYellow() {
    for (uint8_t i = 0; i < 10; i++) {
        LED_toggle(PORT_B, 1);
        Timer_t0_delay(500);
    }
    LED_off(PORT_B, 1);
}

// Helper function used to blink both yellow LEDs
void blinkYellow() {
    for (uint8_t i = 0; i < 10; i++) {
        LED_toggle(PORT_A, 1);
        LED_toggle(PORT_B, 1);
        Timer_t2_delay(500);
    }
    LED_off(PORT_B, 1);
}

// Function used to initialize the application
void App_init() {
    // Initialize cars LEDs
    LED_init(PORT_A, 0);
    LED_init(PORT_A, 1);
    LED_init(PORT_A, 2);

    // Initialize pedestrians LEDs
    LED_init(PORT_B, 0);
    LED_init(PORT_B, 1);
    LED_init(PORT_B, 2);

    // Initialize pedestrians button
    BUTTON_init(PORT_D, 2);
    // Initialize interrupt
    Interrupt_init();
}

void App_normalMode() {
    // Set green state ON and wait 5 seconds to set it OFF
    state = GREEN;
    onCarGreen();
    Timer_t0_delay(5000);
    offCarGreen()

    // Blink car yellow LED
    state = YELLOW_TO_RED;
    blinkCarYellow();

    // Set red state ON and wait 5 seconds to set it OFF
    state = RED;
    onCarRed();
    Timer_t0_delay(5000);
    offCarRed();

    // Blink car yellow LED
    state = YELLOW_TO_GREEN;
    blinkCarYellow();
}

void App_pedestrianMode() {
    // Check whether cars red LED is on or yellow/green
    if (state == RED) {
        // Set pedestrians green LED ON and wait 5 second to set it OFF
        onPedGreen();
        Timer_t2_delay(5000);
    } else {
        // Set pedestrians red LED ON, and blink both yellow LEDs for 5 seconds
        onPedRed();
        offCarYellow();
        blinkYellow();
        // Set both cars green LED & pedestrians red LED OFF, and set both cars red LED & pedestrians green LED ON for 5 seconds
        offCarGreen();
        offPedRed();
        onCarRed();
        onPedGreen();
        Timer_t2_delay(5000);
    }

    // Set cars red LED OFF, and blink both yellow LEDs for 5 seconds
    offCarRed();
    blinkYellow();

    // Set both yellow LEDS & pedestrians green LED OFF
    offCarYellow();
    offPedYellow();
    offPedGreen();

    // Switch to the normal mode
    switch (state) {
        // Interrupted while green state
        case GREEN:
			onCarGreen();
			Timer_t2_delay(5000);
			break;

            // Interrupted while yellow to red state
        case YELLOW_TO_RED:
			onCarGreen();
			Timer_t2_delay(5000);
			offCarGreen();
			blinkCarYellow();
			break;

            // Interrupted while red state
        case RED:
			onCarGreen();
			Timer_t2_delay(5000);
			offCarGreen();
			blinkCarYellow();
			onCarRed();
			Timer_t2_delay(5000);
			break;

            // Interrupted while yellow to green state
        case YELLOW_TO_GREEN:
            break;
    }
}

// External interrupt
ISR (EXT_INT_0) {
	App_pedestrianMode();
}