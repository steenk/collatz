# collatz
Lab with [Collatz Conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture).

The algorithm can be seen as a play with binary numbers, and goes like this:

- 1 at least significant bit --> left shift, add previous number, add one
- 0 at least significant bit --> right shift on step
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

 

