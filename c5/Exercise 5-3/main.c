#include "strcat.h"
#include "test.h"

int main() {

  char s[1000] = "Hello";

  strcat_(s, " world!");

  tests("test1", "Hello world!", s);
  
  strcat_(s, " My name is John!");

  tests("test1", "Hello world! My name is John!", s);

  testresult();
  return 0;
}