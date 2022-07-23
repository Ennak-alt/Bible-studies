#include <ctype.h>
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

/// @brief Check if a char is a hexadecimal
/// @param c is the char to be checked
/// @return 1 if true and 0 if false
int checkIsHex(char c);

/// @brief Calculates 16^n
/// @param n the exponent
/// @return 16^n
int pow16(int n);

/// @brief Converts a single digit to hexadecimal
/// @param c is the digit to be converted
/// @return The digit as a number
int toHex(char c);

/// @brief Converts string to its hexadecimal representation
/// @param s the string to be converted
/// @return The hexadecimal number or -1 if an error occurs
int htoi(char s[]);

int main() {

  printf("\033[33mTests for checkIsBetween:\n");
  test("TEST_CAPITAL_A", 1, checkIsHex('A'));
  test("TEST_CAPITAL_F", 1, checkIsHex('F'));
  test("TEST_LOWER_A", 1, checkIsHex('a'));
  test("TEST_0", 1, checkIsHex('0'));
  test("TEST_9", 1, checkIsHex('9'));
  test("TEST_LOWER_G", 0, checkIsHex('G'));
  test("TEST_LOWER_Z", 0, checkIsHex('z'));

  printf("\n\033[33mTests for htoi:\n");
  test("TEST_JUST_4", 0x4, htoi("4"));
  test("TEST_STARTER_LETTER", 0x8, htoi("0x8"));
  test("TEST_WITH_STARTER_CAPITAL_LETTER", 0x8, htoi("0X8"));
  test("TEST_WITH_LETTER", 0xF, htoi("0XF"));
  test("TEST_47", 0x2F, htoi("0x2F"));
  test("TEST_BIG_NUMBER", 0xFD253A, htoi("Fd253A"));
  test("TEST_ERROR", -1, htoi("FD253G"));

  return 0;
}

int checkIsHex(char c) {
  char lowC = tolower(c);
  return (lowC >= 'a' && lowC <= 'f') || isdigit(lowC) ? 1 : 0;
}

int pow16(int n) {
  return 1 << (4*n);
}

int toHex(char c) {
  return isdigit(c) ? c - '0' : tolower(c) - 'a' + 10;
}

int htoi(char s[]) {
  int i = strlen(s) >= 2 && s[0] == '0' && tolower(s[1]) == 'x' ? 2 : 0;
  int sum = 0;
  int digits = strlen(s) - i;
  for (; s[i] != '\0'; ++i) {
    if (!checkIsHex(s[i])) 
      return -1;
    sum += toHex(s[i]) * pow16(--digits);
  }
  return sum;
}