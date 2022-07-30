#include <math.h>
#include <stdio.h>

void test(char testName[], double expected, double output);

double atof(char s[]);

int main() {

  test("TEST_1", 1, (int)((fabs(atof("123.45e-6") - 123.45e-6)) < 0.0000000001));

  test("TEST_2", 1, (int)((fabs(atof("123.45E-6") - 123.45e-6)) < 0.0000000001));

  // Technically shouldn't compare doubles, but since the number is big enough it works
  test("TEST_2", 123.45E6, atof("123.45E6"));

  test("TEST_2", -123.45E6, atof("-123.45E6"));

  return 0;
}