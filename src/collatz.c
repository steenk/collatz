#include <stdio.h>
#include <stdlib.h>
#include "binary64.h"

int main (int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: collatz <long integer | unsigned binary (0b1101)>\n");
    return 0;
  }

  unsigned long long a = parse_number(argv[1]); //strtol(argv[1], NULL, 10);
  unsigned long long b = 0;
  unsigned long n = 0;
  int bits = 0, turning_point = 0;
  int max_bits = binary_length(a);
  int start_bits = max_bits;
  unsigned long start_number = a;

  printf("%10lu: %20llu  %s\n", n++, a, binary64(a));

  while (a > 1) {
    if ((a & 1) == 1) {
      b = a;
      a = a << 1;
      a = a + b;
      a = a + 1;
    } else {
      a = a >> 1;
    }
    bits = binary_length(a);
    if (bits >= max_bits) {
      max_bits = bits;
      turning_point = n;
    }

    printf("%10lu: %20llu  %s\n", n, a, binary64(a));
    n++;
  }

  printf("\n%29s: %lu\n", "Start number", start_number);
  printf("%29s: %d\n", "Start bit length", start_bits);
  printf("%29s: %d\n", "Max bit length", max_bits);
  printf("%29s: after %d iterations\n", "Turning point", turning_point);
  printf("%29s: %lu\n", "Total iterations", n - 1);

  printf("\n");
}
