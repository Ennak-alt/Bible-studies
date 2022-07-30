#include <stdio.h>

void test(char testName[], double expected, double ouput) {
  if (expected == ouput) {
    printf("\033[0m%s: \033[0;32mSUCEEDED \n", testName);
  } else {
    printf("\033[0m%s: \033[0;31mFAILED \n", testName);
    printf("\033[0;31m   Expected: \"%f\" but got \"%f\" \n", expected, ouput);
  }
}