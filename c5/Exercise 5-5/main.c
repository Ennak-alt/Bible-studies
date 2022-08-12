#include <stdio.h>
#include "strlib.h"
#include "test.h"

int main() {
  printf("STRNCPY TESTS:\n");

  char test[1000];

  strncpy_(test, "Hello world!", 5);

  tests("strncpy_test_1", "Hello", test);

  strncpy_(test, "Hello world!", 2);

  tests("strncpy_test_1", "He", test);

  strncpy_(test, "Hello world!", 13);

  tests("strncpy_test_2", "Hello world!", test);

  strncpy_(test, "Hello world!", 29);

  tests("strncpy_test_3", "Hello world!", test);
  testresult();
  testreset();

  printf("/*--------------------------------------------*/\n");

  printf("STRNCAT TESTS:\n");

  char test2[1000] = "Hello";

  strncat_(test2, " world!", 2);

  tests("strncat_test_1", "Hello w", test2);

  strncat_(test2, "orld!", 4);

  tests("strncat_test_2", "Hello world", test2);

  strncat_(test2, "!", 2);

  tests("strncat_test_3", "Hello world!", test2);  
  testresult();
  testreset();

  printf("/*--------------------------------------------*/\n");

  printf("STRNCMP TESTS:\n");

  testi("strncmp_test_1", 0, strncmp_("Hello", "Herro", 2));

  testi("strncmp_test_1", -1, strncmp_("Healo", "Hebko", 3));

  testi("strncmp_test_1", 1, strncmp_("Heblo", "Hearo", 3));

  testi("strncmp_test_1", 1, strncmp_("Heblo", "Hearo", 5));

  testi("strncmp_test_1", 0, strncmp_("Hello", "Hello", 6));

  testresult();
  testreset();
  printf("/*--------------------------------------------*/\n");
}