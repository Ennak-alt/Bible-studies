#include <stdio.h>
int ogbitcount(unsigned x, int * n) {
  int b,c;
  
  for (b = c = 0; x != 0; x >>= 1) {
    c++;
    if (x & 01)
      b++;
  } 
  (*n) = c;
  return b;
}

int newbitcount(unsigned x, int * n) {
  int b;

  for (b = 0; x != 0; x &= (x-1))
    b++;

  *n = b;

  return b;
}

int main() {
  int test = 0b1;

  int og, new; 

  og = new = 0;

  test = 0b100;
  printf("og: %d, new: %d \n", ogbitcount(test, &og), newbitcount(test, &new));
  printf("og: %d vs new: %d\n\n", og, new);

  test = 0b1000000;
  printf("og: %d, new: %d \n", ogbitcount(test, &og), newbitcount(test, &new));
  printf("og: %d vs new: %d\n\n", og, new);

  test = 0b1000000000000;
  printf("og: %d, new: %d \n", ogbitcount(test, &og), newbitcount(test, &new));
  printf("og: %d vs new: %d\n\n", og, new);

  test = 0b10000000000000000000;
  printf("og: %d, new: %d \n", ogbitcount(test, &og), newbitcount(test, &new));
  printf("og: %d vs new: %d\n\n", og, new);

  test = 0b1111111111111111111111111111111;
  printf("og: %d, new: %d \n", ogbitcount(test, &og), newbitcount(test, &new));
  printf("og: %d vs new: %d\n\n", og, new);

  test = 0b10000000000000000000000000000000;
  printf("og: %d, new: %d \n", ogbitcount(test, &og), newbitcount(test, &new));
  printf("og: %d vs new: %d\n\n", og, new);

  return 0;
}