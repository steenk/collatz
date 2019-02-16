#include <stdlib.h>
#include <stdbool.h>

unsigned long long parse_number (char *str) {
  unsigned long long n = 0;
  if (str[0] == '0' && str[1] == 'b') {
    int i = 2;
    while (str[i] != '\0') {
      if (str[i] == '1') {
        n <<= 1;
        n++;
      } else if (str[i] == '0') {
        n <<=1;
      } else {
        return 0;
      }
      i++;
    }
  } else {
    n = strtol(str, NULL, 10);
  }
  return n;
}

char *binary64 (unsigned long long num) {
  static char str[65] = "";
  unsigned long long n = num;
  unsigned long long LEFTISH = 0x8000000000000000;
  char ZERO = '0', ONE = '1', BLANK = '_';
  bool on = false;
  for (int i=0; i<64; i++) {
    int b = (n & LEFTISH) >> 63;
    n <<= 1;
    if (on) {
      if (b) {
        str[i] = ONE;
      } else {
        str[i] = ZERO;
      }
    } else {
      if (b) {
        on = true;
        str[i] = ONE;
      } else {
        str[i] = BLANK;
      }
    }
  }
  str[64] = '\0';
  return str;
}

int binary_length (unsigned long long num) {
  int len = 0, pos = 1;
  unsigned long long n = num;
  while (pos < 64) {
    if (n & 1) {
      len = pos;
    }
    pos++;
    n >>= 1;
  }
  return len;
}


