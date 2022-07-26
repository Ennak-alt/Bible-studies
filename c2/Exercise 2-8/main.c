#include <stdio.h>
#include <stdlib.h>
#define INT_BITS 32

void test(char testName[], int expected, int ouput) {
  if (expected == ouput) {
    printf("\033[0m%s: \033[0;32mSUCEEDED \n", testName);
  } else {
    printf("\033[0m%s: \033[0;31mFAILED \n", testName);
    printf("\033[0;31m   Expected: \"%d\" but got \"%d\" \n", expected, ouput);
  }
}

/// @brief Rotates n bits of number to the right
/// @param x the number to rotate the bits
/// @param n the number of bit positions to rotate
/// @return The number with it's bits changed
int rightrot(int x, int n);

int main() {

  test("INVERT_TEST1", 0b1, rightrot(0b10, 1));

  test("INVERT_TEST2", 0b1, rightrot(0b100, 2));
  test("INVERT_TEST3", 0b1010101, rightrot(0b1010101000, 3));

  test("INVERT_TEST4", 0b1010000000000000000000000000011, rightrot(0b11101, 3));

  return 0;
}

int rightrot(int x, int n) {
  // -1 is because the last bit is reserved to be a signed bit
  return ((x & ~(~0 << n)) << (INT_BITS-n-1)) | (x >> n); 
}