#include <stdio.h>

char const UPLOW_DIST = 'a' - 'A'; // 32

void test(char testName[], char expected, char ouput) {
  if (expected == ouput) {
    printf("\033[0m%s: \033[0;32mSUCEEDED \n", testName);
  } else {
    printf("\033[0m%s: \033[0;31mFAILED \n", testName);
    printf("\033[0;31m   Expected: \"%c\" but got \"%c\" \n", expected, ouput);
  }
}

/// @brief Makes char lowercase
/// @param c the char to make lowercase
/// @return The char but in lower case
int lower(char c);

int main() {

  test("TEST_1", 'a', lower('A'));

  test("TEST_1", 'a', lower('a'));

  test("TEST_1", 'z', lower('Z'));

  return 0;
}

int lower(char c) {
  return (c >= 'A' && c <= 'Z') ? c + UPLOW_DIST : c;
}