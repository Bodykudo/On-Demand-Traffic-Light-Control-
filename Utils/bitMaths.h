#ifndef BIT_MATHS
#define BIT_MATHS

#define SET_BIT(X, BIT_NO) (X |= (1 << BIT_NO));
#define CLR_BIT(X, BIT_NO) (X &= ~(1 << BIT_NO));
#define READ_BIT(X, BIT_NO) ((X & (1 << BIT_NO)) >> BIT_NO);
#define TOGGLE_BIT(X, BIT_NO) (X ^= (1 << BIT_NO));

#endif