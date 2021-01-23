#!/bin/bash

rm -r ./results 2>/dev/null
mkdir -p ./results

for I in `seq 0 255`; do
    IX=`printf '%02X\n' $I`
    FILENAME="${IX}A3"

    echo -n "0x$IX "
    rm ./xoroshiro16.bin 2>/dev/null
    ./xoroshiro16test $I \
        && dieharder -a -n 2 -g 201 -f ./xoroshiro16.bin \
        >> "./results/$FILENAME.txt"
done
