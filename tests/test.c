#include <stdio.h>
#include <string.h>

#define SUCCESS "\033[0;32m"
#define ERROR "\033[0;31m"
#define NORMAL "\033[0m"

void changeclr(int i) {
  switch (i)
  {
  case 0:
    printf(SUCCESS);
    break;
  case 1: 
    printf(ERROR);
    break;
  default:
    printf(NORMAL);
    break;
  }
}

static int testnumber;
static int testsucc;

void testi(char testName[], int expected, int ouput) {
  testnumber++;
  printf("%s: ", testName);
  if (expected == ouput) {
    testsucc++;
    changeclr(0);
    printf("SUCCEEDED \n\tExpected: %d\n", expected);
  } else {
    changeclr(1);
    printf("FAILED \n\tExpected: \"%d\" but got \"%d\" \n", expected, ouput);
  }
  changeclr(-1);
}

void tests(char testName[], char expected[], char ouput[]) {
  testnumber++;
  printf("%s: ", testName);
  if (!strcmp(expected, ouput)) {
    testsucc++;
    changeclr(0);
    printf("\tSUCCEEDED \n\tExpected: %s\n", expected);
  } else {
    changeclr(1);
    printf("\tFAILED \n\tExpected: \"%s\" but got \"%s\" \n", expected, ouput);
  }
  changeclr(-1);
}

void testreset() {
  testnumber = testsucc = 0;
}

void testresult(void) {
  printf("Test result: ");
  if (testnumber == testsucc) 
    changeclr(0);
  else 
    changeclr(1);
  printf("%d / %d \n", testsucc, testnumber);
  changeclr(-1);
}