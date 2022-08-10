#include <stdio.h>
#include "getnum.h"

int main() {
  int var = 10023;
  getint(&var);
  printf("Result: %d\n", var);
  double var2 = 1.3245f;
  getfloat(&var2);
  printf("Result: %lf\n", var2);
  return 0;
}