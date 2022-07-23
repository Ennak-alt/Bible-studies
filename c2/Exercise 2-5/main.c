#include <string.h>
#include <stdio.h>

void test(char testName[], int expected, int ouput) {
  if (expected == ouput) {
    printf("\033[0m%s: \033[0;32mSUCEEDED \n", testName);
  } else {
    printf("\033[0m%s: \033[0;31mFAILED \n", testName);
    printf("\033[0;31m   Expected: \"%d\" but got \"%d\" \n", expected, ouput);
  }
}

/// @brief Returns the first location in a string where any character from another string occurs
/// @param s1 string that will get its characters checked
/// @param s2 the string to check up against
/// @return Index of char occurence or -1 if there isn't any
int any(char s1[], char s2[]);

int main() {

  test("TEST_1", 1, any("jello", "hello world!"));

  test("TEST_2", 4, any("jello", "ohhhh"));

  test("TEST_ERROR", -1, any("Jello", "Fuck"));

  return 0;
}

int any(char s1[], char s2[]) {
  for (int i = 0; s1[i] != '\0'; i++) 
    for (int j = 0; s2[j] != '\0'; j++)
      if (s1[i] == s2[j]) 
        return i;
  return -1;
}