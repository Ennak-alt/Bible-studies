#include <stdio.h>

void test(char testName[], int expected, int ouput);

int strrindex(char s[], char t[]);

int main() {
  test("TEST_1", 8, strrindex("ejejejejej", "ej"));

  test("TEST_2", 8, strrindex("ejejejejejg", "ej"));

  test("TEST_3", -1, strrindex("ejejejejej", "yj"));
}

void test(char testName[], int expected, int ouput) {
  if (expected == ouput) {
    printf("\033[0m%s: \033[0;32mSUCEEDED \n", testName);
  } else {
    printf("\033[0m%s: \033[0;31mFAILED \n", testName);
    printf("\033[0;31m   Expected: \"%d\" but got \"%d\" \n", expected, ouput);
  }
}
