#include <stdio.h>

#define swap(t, x, y)\
          t temp = y;\
          y = x;\
          x = temp;
  

int main() {
  int x = 1234;
  int y = 92157;

  printf("x: %d, y: %d\n", x, y);

  swap(int, x, y);

  printf("x: %d, y: %d\n", x, y);

  return 0;
}