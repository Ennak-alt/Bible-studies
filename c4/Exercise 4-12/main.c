#include <stdio.h>
#include <string.h>

void test(char[], char[], char[]);

void printd(int, char[]);

int main() {
  char str[1000];

  printd(1234567890, str);

  test("TEST_1", "1234567890", str);

  printd(54322324, str);

  test("TEST_2", "54322324", str);

  printd(100000, str);

  test("TEST_2", "100000", str);

  return 0;
}

void printd(int n, char str[]) {
  static int i = 0;
  
  str[i++] = (n % 10) + '0';

  if (n < 10) {
    str[i--] = '\0';
    
    // Reverse characters in string
    for (int j = 0; j < i; j++, i--) {
      char c = str[j];
      str[j] = str[i];
      str[i] = c;
    }
    
    i = 0;
    return;
  }
  
  printd(n / 10, str);
}


void test(char testName[], char expected[], char ouput[]) {
  if (strcmp(expected, ouput) == 0) {
    printf("\033[0m%s: \033[0;32mSUCEEDED \n", testName);
  } else {
    printf("\033[0m%s: \033[0;31mFAILED \n", testName);
    printf("\033[0;31m   Expected: \"%s\" but got \"%s\" \n", expected, ouput);
  }
}