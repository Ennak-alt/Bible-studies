#include <stdio.h>
#define MAXOP 10000
static int stack[MAXOP];
const int *pi = stack;
static int *p = stack;
const int *pj = stack+MAXOP;

void push(int i) {
  if (p >= pj) {
    printf("Stack full!\n");
    return;
  }
  *p++ = i;
}

int pop() {
  if (p <= pi) {
    printf("Stack empty!\n");
    return 0;
  }
  return *--p;
}