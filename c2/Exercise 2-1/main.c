#include <stdio.h>
#include <limits.h>

int main() {
  printf("char-min: %d \n", CHAR_MIN);
  printf("char-max: %d \n", CHAR_MAX);
  printf("char-unsigned-max: %d \n", UCHAR_MAX);
  printf("short-min: %d \n", SHRT_MIN);
  printf("short-max: %d \n", SHRT_MAX);
  printf("short-unsigned-max: %d \n", USHRT_MAX);
  printf("int-min: %d \n", INT_MIN); 
  printf("int-max: %d \n", INT_MAX);
  printf("int-unsigned-max: %u \n", UINT_MAX);
  printf("long-min: %ld \n", LONG_MIN); 
  printf("long-max: %ld \n", LONG_MAX);
  printf("long-unsigned-max: %lu \n", ULONG_MAX);

  printf("__________________________________\n");

  printf("char-min: %d \n", -(2<<6));
  printf("char-max: %d \n", (2<<6) - 1);
  printf("char-unsigned-max: %d \n", 2<<7);
  printf("short-min: %d \n", -(2<<14));
  printf("short-max: %d \n", (2<<14)-1);
  printf("short-unsigned-max: %d \n", 2<<15);
  printf("int-min: %d \n", (2<<30)); 
  printf("int-max: %ld \n", (2L<<30L)-1L);
  printf("int-unsigned-max: %ld \n", (2L<<31L)-1);
  printf("long-min: %ld \n", -(2L<<62L)); 
  printf("long-max: %ld \n", (2UL<<62UL)-1UL);
  printf("long-unsigned-max: %lu \n", (2UL<<63UL)-1UL);

  return 0;
}