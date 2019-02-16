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
1st iteration:                                    1111
                                               +   111
2nd iteration:                                 = 10110
Now the number has a 0 as the LSB, so we right shift one step.
3rd iteration:                                    1011

And continue until we have just 1 left:
4th iteration:                                  100010
5th iteration:                                   10001
6th iteration:                                  110100
7th iteration:                                   11010
8th iteration:                                    1101
9th iteration:                                  101000
10th iteration:                                  10100
11th iteration:                                   1010
12th iteration:                                    101
13th iteration:                                  10000
14th iteration:                                   1000
15th iteration:                                    100
16th iteration:                                     10
17th iteration:                                      1
```

 

