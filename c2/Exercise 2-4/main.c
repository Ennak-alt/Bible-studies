#include <string.h>
#include <stdio.h>

void test(char testName[], char expected[], char ouput[]) {
  if (strcmp(expected, ouput) == 0) {
    printf("\033[0m%s: \033[0;32mSUCEEDED \n", testName);
  } else {
    printf("\033[0m%s: \033[0;31mFAILED \n", testName);
    printf("\033[0;31m   Expected: \"%s\" but got \"%s\" \n", expected, ouput);
  }
}

/// @brief Remove all ocurrences of characters in one string from another string
/// @param s1 string that will be removed from
/// @param s2 string that will be compared to
/// @return Alters s1
void squeeze(char s1[], char s2[]);

/// @brief Check if a char is in a string
/// @param c char to check
/// @param s string to look through
/// @return 1 if true and 0 if false
int charInString(char c, char s[]);

int main() {

  char s1[] = "osalamizp";
  squeeze(s1, "poz");
  test("TEST_1", "salami", s1);

  char s2[] = "AppLE";
  squeeze(s2, "aPPLE");
  test("TEST_CASE_SENSITIVITY", "App", s2);

  return 0;
}

int charInString(char c, char s[]) {
  for (int i = 0; s[i] != '\0'; i++)
    if (c == s[i])
      return 1;
  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i,j;
  for (i = j = 0; s1[i] != '\0'; i++)
    if (!charInString(s1[i], s2)) 
      s1[j++] = s1[i];
  s1[j] = '\0';
}