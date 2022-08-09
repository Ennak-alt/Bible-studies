#include <stdio.h>
#include <string.h>

void test(char[], char[], char[]);

void reverse(char[]);

int main() {
  char str[] = "Try not. Do or do not. There is no try";

  reverse(str);

  test("TEST_1", "yrt on si erehT .ton od ro oD .ton yrT", str);

  reverse(str);

  test("TEST_2", "Try not. Do or do not. There is no try", str);

  return 0;
}

// More parameters than one is 
void reverse(char str[]) {
  static int i = 0, j;

  if (i == 0)
    j = strlen(str) - 1;

  if (i > j) {
    i = 0;
    return;
  } 
    
  char c = str[i];

  str[i++] = str[j];
  str[j--] = c;

  reverse(str);
}


void test(char testName[], char expected[], char ouput[]) {
  if (strcmp(expected, ouput) == 0) {
    printf("\033[0m%s: \033[0;32mSUCEEDED \n", testName);
  } else {
    printf("\033[0m%s: \033[0;31mFAILED \n", testName);
    printf("\033[0;31m   Expected: \"%s\" but got \"%s\" \n", expected, ouput);
  }
}