#include <stdio.h>

void test(char testName[], int expected, int ouput) {
  if (expected == ouput) {
    printf("\033[0m%s: \033[0;32mSUCEEDED \n", testName);
  } else {
    printf("\033[0m%s: \033[0;31mFAILED \n", testName);
    printf("\033[0;31m   Expected: \"%d\" but got \"%d\" \n", expected, ouput);
  }
}

/// @brief Iverts n bits at position p
/// @param x the number to invert the bits
/// @param p the position to invert the bits
/// @param n number of bits to change invert
/// @return The number with it's bits changed
int invert(int x, int p, int n);

int main() {

  test("INVERT_ONE_BIT", 0b1, invert(0b0, 0, 1));

  test("INVERT_4_BITS", 0b0001111000, invert(0b0000000000, 3, 4));

  test("INVERT_ONE_BIT", 0b0101001011, invert(0b0101010101, 1, 4));

  return 0;
}

int invert(int x, int p, int n) {

  int invx = ~x; // Inverted version of x
  invx = invx & (~(~0 << n) << p); // Get the n bits at the correct position

  printf("%d", invx);

  int r = ~(~(~0 << n) << p); // Create reset bits

  x &= r; // Reset bits
  x |= invx; // Set bits

  return x;
}

