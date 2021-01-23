/* CC0 [Josip Medved](http://medo64.com) */

#include "xoroshiro16.h"
#ifdef __XC8
    #include <xc.h>
#else
    #include <time.h>
#endif

#define SEED_CONSTANT 0xA3

#ifdef __OPTIM_SPEED
    #define rotl(x, k)  (x << k) | (x >> (8 - k))
#else
    uint8_t rotl(const uint8_t x, const uint8_t k) {
        return (x << k) | (x >> (8 - k));
    }
#endif

uint8_t s[2] = { 0, SEED_CONSTANT };

void random_init(void) {
#ifdef __XC8
    // setup timer if not already in use
    T1CONbits.TMR1CS = 0b11;
    T1CONbits.T1OSCEN = 1;
    T1CONbits.TMR1ON = 1;

    _delay(4096);  // just to improve randomness of timer - can be omitted

    // initialize using timer values
    s[0] = TMR1L;
    s[1] = SEED_CONSTANT;
#else
    s[0] = (uint8_t)time(0);
    s[1] = SEED_CONSTANT;
#endif
}

void random_init_seed(const uint8_t seed) {
    s[0] = seed;
    s[1] = SEED_CONSTANT;
}

uint8_t random_next(void) {
    uint8_t s0 = s[0];
    uint8_t s1 = s[1];
    uint8_t result = s0 + s1;

    s1 ^= s0;
    s[0] = rotl(s0, 6) ^ s1 ^ (s1 << 1);
    s[1] = rotl(s1, 3);

    return result;
}
