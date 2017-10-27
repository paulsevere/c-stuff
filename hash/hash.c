#include <stdio.h>

#define MULTIPLIER (91)

unsigned long hash(const char *s) {
  unsigned long h;
  unsigned const char *us;
  us = (unsigned const char *)s;
  h = 0;
  while (*us != '\0') {
    h = h * MULTIPLIER + *us;
    us++;
  }
  return h % 1000;
}

int main(int argc, char **argv) {
  unsigned long res;
  res = hash(argv[1]);
  printf("%lu\n", res);
  return 0;
}