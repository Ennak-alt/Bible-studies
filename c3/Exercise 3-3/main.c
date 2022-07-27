#include <string.h>
#include <stdio.h>
#include <ctype.h>

void test(char testName[], char expected[], char ouput[]) {
  if (strcmp(expected, ouput) == 0) {
    printf("\033[0m%s: \033[0;32mSUCEEDED \n", testName);
  } else {
    printf("\033[0m%s: \033[0;31mFAILED \n", testName);
    printf("\033[0;31m   Expected: \"%s\" but got \"%s\" \n", expected, ouput);
  }
}

/// @brief Expand shorthand notation like a-z
/// @param s1 string to expand from
/// @param s2 string to copy expanded string to
/// @return alters s2 to the expanded form of s1
void expand(char s1[], char s2[]);

int main() {
  char s[1000];

  char t1[] = "a-z";

  expand(t1, s);
  test("TEST_1", "abcdefghijklmnopqrstuvwxyz", s);

  char t2[] = "a-zA-Z0-9";

  expand(t2, s);
  test("TEST_2", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", s);

  char t3[] = "a-b-c";

  expand(t3, s);
  test("TEST_2", "abc", s);

  char t4[] = "-a-z";

  expand(t4, s);
  test("TEST_2", "-abcdefghijklmnopqrstuvwxyz", s);

  char t5[] = "-a-Z-A-0-2-A9-0z-a-";

  expand(t5, s);
  test("TEST_2", "-a-Z-A-012-A9-0z-a-", s);

  return 0;
}

int isexpandable(char s[], int i) {
  return (
      isalnum(s[i]) 
      && s[i+1] == '-' 
      && isalnum(s[i+2]) 
    && 
      s[i] <= s[i+2]
    && 
      (isdigit(s[i]) && isdigit(s[i+2]) 
      || islower(s[i]) && islower(s[i+2]) 
      || isupper(s[i]) && isupper(s[i+2]))
  );
}

void expand(char s1[], char s2[]) {
  int i,j;
  for (i = j = 0; s1[i] != '\0'; i++) {
    if (isexpandable(s1, i)) {
      do {
        for (char c = s1[i]; c <= s1[i+2]; c++) {
          s2[j++] = c;
        }
        i += 2, j--;
      } while (isexpandable(s1, i));
      j++;
    } else {
      s2[j++] = s1[i];
    }
  }
  s2[j] = '\0';
}