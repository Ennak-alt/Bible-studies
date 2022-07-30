#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void test(char testName[], char expected[], char ouput[]) {
  if (strcmp(expected, ouput) == 0) {
    printf("\033[0m%s: \033[0;32mSUCEEDED \n", testName);
  } else {
    printf("\033[0m%s: \033[0;31mFAILED \n", testName);
    printf("\033[0;31m   Expected: \"%s\" but got \"%s\" \n", expected, ouput);
  }
}

void reverse(char s[]) {
    int i = 0;
    char cp[1000];
    while (s[i] != '\0') {
        cp[i] = s[i];
        ++i;
    }
    --i;
    for (int j = 0; i >= 0; ++j, --i) {
        s[j] = cp[i];
    }
}

void newitoa(int n, char s[]) {
  int i, sign;
  char l;
  
  i = 0;

  if ((sign = n) < 0) {
    s[0] = (char)(-(n - (n/10)*10) + '0');
    i++;
    n = -(n / 10);
  }

  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  s[++i] = '\0';
  reverse(s);
}

/// @brief Calculates the logarithm with base b
/// @param n the number to take logb to
/// @param b the base of the logarithm
/// @return Logarithm of n with base b
int logbs(int n, int b);

/// @brief Converts number to a specific base
/// @param n the number to take convert
/// @param s the string to copy to
/// @param b the base
/// @return Logarithm of n with base b
void itob(int n, char s[], int b);

int main() {

  char s[1000];
  itob(31, s, 16);

  test("TEST_1", "16_1F", s);

  itob(10, s, 2);

  test("TEST_2", "2_1010", s);

  itob(10, s, 3);

  test("TEST_3", "3_101", s);

  itob(25, s, 8);

  test("TEST_4", "8_31", s);

  itob(7562, s, 8);

  test("TEST_5", "8_16612", s);

  return 0;
}

int logbs(int n, int b) {
  return (int)(log10(n)/log10(b));;
}

int toChar(int i) {
  return i + '0' <= '9' ? i + '0' : i + 'A' - 10;
}

void itob(int n, char s[], int b) {
  
  int i;
  for (i = 0; n != 0; i++) {
    int r = n % b;
    n /= b;
    s[i] = toChar(r);
  }

  char sn[100];
  newitoa(b, sn);

  s[i++] = '_';

  for (int j = strlen(sn)-1; j >= 0; j--, i++) 
    s[i] = sn[j];

  s[i] = '\0';

  reverse(s);
}

