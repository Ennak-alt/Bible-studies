#include "pointer_versions.h"
#include <stdio.h>
#include "test.h"

int main() {
  char str[1000];
  getlinePV(str);
  tests("test_get", "Hello world!", str);
  reversePV(str);
  tests("test_rev", "!dlrow olleH", str);
  getlinePV(str);
  tests("test_getEOF", "Hello world!", str);
  reversePV(str);
  tests("test_revEOF", "!dlrow olleH", str);
  testresult();
  return 0;
}