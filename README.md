Xoroshiro16
===========

This is my take on [xoroshiro](http://prng.di.unimi.it/) algorithm
maintaining its state in 16 bits while returning 8 bits at a time.

It's designed for memory-constrained Microchip PIC microcontrollers
without hardware multiplication circuits.

Seed allows for 256 different initial states, each having a 64,897
bytes period. While this might barely pass a few DieHarder tests (e.g.
birthdays, 2dsphere, dab_dct, and/or rgb_permutations), it won’t come
even close to the full [xoroshiro64**](http://prng.di.unimi.it/xoroshiro64starstar.c)
in terms of randomness quality.

Original [xoshiro/xoroshiro](http://prng.di.unimi.it/) were written by
David Blackman and Sebastiano Vigna.
