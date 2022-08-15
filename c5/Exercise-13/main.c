#include "fixed_queue.h"

int main() {
  char *queue[2];
  alloc("a", queue, 2);
  alloc("b", queue, 2);
  alloc("c", queue, 2);
  alloc("d", queue, 2);
  alloc("e", queue, 2);
  alloc("f", queue, 2);
  alloc("g", queue, 2);
  alloc("h", queue, 2);
  printq(queue, 2);
}
