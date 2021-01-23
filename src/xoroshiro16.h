#ifndef XOROSHIRO16_H
#define	XOROSHIRO16_H

#include <stdint.h>

/** Initializes random number seed from LFINTOSC. */
void random_init(void);

/** Initializes random number seed directly. */
void random_init_seed(const uint8_t seed);

/** Returns next random number. */
uint8_t random_next(void);

#endif
