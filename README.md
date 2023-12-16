# collatz
Lab with [Collatz Conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture).

The algorithm can be seen as a play with binary numbers, and goes like this:

- 1 at least significant bit --> left shift, add previous number, add one
- 0 at least significant bit --> right shift one step
- stop on 1

The sequence will finally be a 1 followed by 0s, and then it goes down to 1 by repeating right shifts.

**Example**

```
Take the number 7 in (unsigned) binary:            111
The least significant bit (LSB) is 1, left shift  1110
and add 1:                                        1111
Then add the first number to the answer:
                                                  1111
                                               +   111
1st iteration:                                 = 10110
Now the number has a 0 as the LSB, so we right shift one step.
2nd iteration:                                    1011

And continue until we have just 1 left:
3rd iteration:                                  100010
4th iteration:                                   10001
5th iteration:                                  110100
6th iteration:                                   11010
7th iteration:                                    1101
8th iteration:                                  101000
9th iteration:                                   10100
10th iteration:                                   1010
11th iteration:                                    101
12th iteration:                                  10000
13th iteration:                                   1000
14th iteration:                                    100
15th iteration:                                     10
16th iteration:                                      1
```

 

Every addition can increase the length of the number by one, if a carry number slips all the way to the left side of the number. We have two additions, so it is possible our number length will increase by 2 if the LSB is 1. If the LSB is 0, then our number length decreases by 1. It can seems like there is a possibility to get a number that increases in length faster than it decreases, but all numbers with a fixed length will eventually run out of 1s, and our algorithm is steadily feading in 0s from the right, so the conjucture says eventually every positive number will end up as 1. It feels intuitively correct, but we lack a mathematical proof.

## Build and run

This is a c command line tool, so you need to have a c compiler installed. Download the src folder and run `make` inside it. The `collatz` command takes a large integer, or a binary string (starting with "0b"). Overflow will happen if it grows over 64 bits.

