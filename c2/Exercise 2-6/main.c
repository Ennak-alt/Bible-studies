#include <stdio.h>

void test(char testName[], int expected, int ouput) {
  if (expected == ouput) {
    printf("\033[0m%s: \033[0;32mSUCEEDED \n", testName);
  } else {
    printf("\033[0m%s: \033[0;31mFAILED \n", testName);
    printf("\033[0;31m   Expected: \"%d\" but got \"%d\" \n", expected, ouput);
  }
}

/// @brief Set bits that begin at position to the right most n bits of another number.
/// @param x the number to change the bits
/// @param p the position to set the bits
/// @param n number of rightmost bits to change to
/// @param y the number to change from
/// @return The number with it's bits changed
int setbits(int x, int p, int n, int y);

int main() {
  test("TEST_CHANGE_ONE_BIT", 0b0, setbits(0b1, 0, 1, 0b0));
  test("TEST_CHANGE_TWO_BITS", 0b1010, setbits(0b0010, 1, 3, 0b101));
  test("TEST_CHANGE_FOUR_BITS", 0b000111, setbits(0b001100, 0, 4, 0b100111));
  test("TEST_CHANGE_BITS_MIDDLE", 0b0011100, setbits(0b0000000, 2, 3, 0b100111));
  test("TEST_CHANGE_ALTERNATING_BITS", 0b1011, setbits(0b10101, 1, 4, 0b10101));

  return 0;
}

int setbits(int x, int p, int n, int y) {  
  y &= ~(~0 << n); // Get n bits at rightmost position
  y <<= p; // Left shift them to the correct position

  int r = ~(~(~0 << n) << p); // Create n 1 bits, shift them to the correct position and complement

  x &= r; // Reset the n bits at position p
  x |= y; // Change the bits to the n rightmost bits in y

  // (x & ~(~(~0 << n) << p)) | ((y & ~(~0 << n)) << p)

  return x;
}