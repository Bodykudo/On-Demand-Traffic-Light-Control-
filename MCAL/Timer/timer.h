#ifndef TIMER
#define TIMER

// Including libraries
#include "../../utils/types.h"
#include "../../utils/bitMaths.h"
#include "../../utils/registers.h"

// Driver functions prototypes
void Timer_t0_init();
void Timer_t0_delay(float mSeconds);
void Timer_t2_init();
void Timer_t2_delay(float mSeconds);

#endif