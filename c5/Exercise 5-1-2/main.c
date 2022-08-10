#include <stdio.h>
#include "getint.h"

int main() {
  int var = 10023;
  getint(&var);
  printf("Result: %d\n", var);
  return 0;
}