#include "test.h"
#include "strend.h"

int main() {
  testi("test1", 0, strend("Hello world!", "world"));

  testi("test2", 1, strend("Hello world!", "world!"));

  testi("test3", 1, strend("Hello ", "o "));

  testi("test4", 1, strend("Hello", ""));

  testi("test5", 0, strend("Hello", " "));

  testi("test6", 0, strend("Hello world!", "Hello world!!"));

  testi("test7", 1, strend("Hello world!", "Hello world!"));

  testresult();
  return 0;
}